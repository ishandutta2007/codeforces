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
using namespace std;
typedef pair<int,int> pt;

int n, a[N], q[N];

int main(){
//    freopen("1.in","r",stdin);  
  //  freopen("1.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    long long ans = 2e18;
    for (int i = 1; i < n; i++) ans = min(ans, 1ll + a[i] * 1ll * a[i]);

    for (int i = 1; i < n; i++) a[i] += a[i - 1];
    for (int i = 1; i < n; i++) for (int j = i - 1; j > -1; j--) {
        int s = (i - j) * (i - j);
        if (s >= ans) break;
        if (abs(a[i] - a[j]) < 10000)
        ans = min(ans, s + (a[i] - a[j]) * 1ll * (a[i] - a[j]));
    }
    cout << ans << endl;
    return 0;
}