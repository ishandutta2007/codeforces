#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
#define A 160111

int n, m;
int a[444][444];
int last[A];
int l[444], r[444];
int ll[444][444], rr[444][444];

pt q[444];

int main(){
//  freopen("1.in","r",stdin);  
//  freopen("1.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    long long ans = 0;
    for (int f = 0; f < n; f++) for (int j = 0; j < m; j++) {
        ll[f][j] = -1;
        rr[f][j] = m;
    }
    for (int s = n - 1; s >= 0; s--) {
        for (int i = 0; i < A; i++) last[i] = -1;
        for (int j = 0; j < m; j++) {
            for (int f = s; f < n; f++) {
                if (last[a[f][j]] != -1) ll[f][j] = max(ll[f][j], last[a[f][j]]);
                last[a[s][j]] = j;
            }
        }
        for (int i = 0; i < A; i++) last[i] = -1;
        for (int j = m - 1; j >= 0; j--) {
            for (int f = s; f < n; f++) {
                if (last[a[f][j]] != -1) rr[f][j] = min(rr[f][j], last[a[f][j]]);
                last[a[s][j]] = j;
            }
        }

        for (int i = 0; i < m; i++) l[i] = -1, r[i] = m;

        for (int f = s; f < n; f++) {
            for (int i = 0; i < m; i++) {
                l[i] = max(l[i], ll[f][i]);
                r[i] = min(r[i], rr[f][i]);
            }
            int u = 0;
            int q1 = 0, q2 = 0;
            for (int i = 0; i < m; i++) {
                {
                    while (q2 < q1 && r[i] <= q[q1 - 1].F) q1--;
                    q[q1++] = mp(r[i], i);
                }
                u = max(u, l[i] + 1);
                while (q2 < q1 && q[q2].S < u) q2++;
                while (q2 < q1 && q[q2].F <= i) {
                    u++;
                    while (q2 < q1 && q[q2].S < u) q2++;
                }

                ans = max(ans, (i - u + 1) * 1ll * (f - s + 1) );
            }
        }
        
    }
    cout << ans << endl;
    return 0;
}