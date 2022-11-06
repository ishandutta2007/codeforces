// Problem: CF1677C Tokitsukaze and Two Colorful Tapes
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1677C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, a[N], b[N], vis[N];
vector<int> cyc;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
    for(scanf("%d", &T);T;T--) {
        scanf("%d", &n);
        rep(i, 1, n) scanf("%d", &a[i]);
        rep(i, 1, n) scanf("%d", &b[a[i]]);
        // rep(i, 1, n) printf("%d%c", b[i], " \n"[i==n]);
        bool same = 1;
        rep(i, 1, n) same &= b[i] == i;
        if(same) {puts("0"); continue;}
        else {
            vector<int>().swap(cyc);
            rep(i, 1, n) vis[i] = 0;
            rep(i, 1, n) {
                if(!vis[i]) {
                    int now = 0;
                    for(int j=i;!vis[j];j=b[j]) {
                        ++now;
                        vis[j] = 1;
                    }
                    cyc.push_back(now);
                }
            }
            sort(cyc.begin(), cyc.end(), greater<int>());
            int now = n; ll ans = 0;
            for(auto x : cyc) {
                ans += (1LL * (now - 1) + (now - 1 - 2 * (x / 2 - 1))) * (x / 2);
                // printf("%d %d %d\n", now-1, now-1-2*(x/2-1), x/2);
                now -= x / 2 * 2;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}