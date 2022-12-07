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
#include<cstring>
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
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
int a[N];
int f[25][1000111];
int gg[1000111];

int fm(int l, int r) {
    int w = gg[r - l + 1];
    return max(f[w][l], f[w][r - pw(w) + 1]);
}

int main(){
//    freopen(TASK".in","r",stdin);   
//    freopen(TASK".out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);

    int maxn = 1000001;

    for (int i = 0; i < maxn; i++) f[0][i] = -1;
    for (int i = 0; i < n; i++) f[0][a[i]] = a[i];

    gg[1] = 0;
    for (int i = 2; i <= maxn; i++) gg[i] = gg[i / 2] + 1;

    for (int i = 1; i <= gg[maxn]; i++) for (int j = 0; j < maxn; j++) 
    if (j + pw(i) > maxn) f[i][j] = -1; else f[i][j] = max(f[i - 1][j], f[i - 1][j + pw(i - 1)]);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i - 1] == a[i]) continue;
        int k = a[i];
        int j = k;
        while (j < maxn) {
            int l = j;
            int r = min(j + k - 1, maxn - 1);

            int v = fm(l, r);
            if (v != -1) ans = max(ans, v % k);

            j += k;
        }
    }
    cout << ans << endl;
    return 0;
}