#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 100000 + 10;
vector<int> g[N];
int n,m,ans[N];
map< pair<int,int>, int > mp;
vector<int> c[4];
pair< vector<int>, int > a[N];
int main() {
    scanf("%d%d", &n,&m);
    for(int i=1;i<=m;i++) {
        int u,v; scanf("%d%d", &u,&v);
        g[u].push_back(v); 
        g[v].push_back(u);
        mp[make_pair(u, v)] = mp[make_pair(v, u)] = 1;
    }
    for(int i=1;i<=n;i++) {
        sort(g[i].begin(), g[i].end());
        a[i] = make_pair(g[i], i);
    }
    sort(a+1,a+1+n);
    vector<int> res; int idx = 0;
    for(int i=1;i<=n;i++) {
        if (i==1 || a[i].first != a[i-1].first) {
            ++ idx;
            ans[ a[i].second ] = idx;
        } else {
            ans[ a[i].second ] = idx;
        }
    }

    if (idx == 3) {
        for (int i = 1; i <= n; i ++) {
            //printf("%d ", ans[i]);
            c[ ans[i] ].push_back(i);
        }

        bool ok = 1;
        for (int i = 1; i <= 3; i++) {
            for (int j = i+1; j <= 3; j ++) {
                // printf("i = %d, j = %d\n", i, j);
                if (ok == 0) break;
                for (auto x: c[i]) {
                     if (ok == 0) break;
                    for (auto y: c[j]) {
                        if (mp[make_pair(x, y)] == 0) {
                            ok = 0; break;
                        }
                    }
                    if (ok == 0) break;
                }
            }
        }

        if (ok == 0) return !printf("-1\n");
        for (int i = 1; i <= n; i ++) {
            printf("%d ", ans[i]);
        }

    } else {
        printf("-1\n");
    }

}