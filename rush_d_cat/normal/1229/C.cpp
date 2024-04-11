#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cstring>
using namespace std;
typedef long long LL;
const int B = 800;
const int N = 200000 + 10;
int n,m,las[N],a[N];
LL in[N],out[N],deg[N];
vector<int> g[N];
unordered_set<LL> st;

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u,v; scanf("%d%d",&u,&v);
        if(u>v)swap(u,v);
        g[u].push_back(v); g[v].push_back(u);
        in[u]++, out[v]++; deg[u]++, deg[v]++;
        st.insert(1LL * n * u + v); st.insert(1LL * n * v + u);
    }    
    for(int i=1;i<=n;i++) {
        las[i]=i; a[i]=i;
    }
    int q; scanf("%d", &q);
    LL ans=0;
    for(int i=1;i<=n;i++) ans += in[i] * out[i];
    printf("%lld\n", ans);
    for(int i=n+1;i<=n+q;i++){
        int x; scanf("%d",&x); a[i]=x;
        //printf("upd %d\n", x);
        if(deg[x] >= B) {
            //printf("ok\n");
            for(int j=las[x]+1;j<i;j++) {
                //printf("j=%d\n", j);
                if(las[a[j]] != j) continue;
                //printf("j2 = %d\n", j);
                if(!st.count(1LL * n * x + a[j])) continue;
                int y = a[j];
                //printf("x=%d, y=%d\n", x,y);
                ans -= (in[x] * out[x] + in[y] * out[y]) ;
                in[x] --; out[x] ++; out[y] --; in[y] ++;
                ans += (in[x] * out[x] + in[y] * out[y]) ;
            }
        } else {
            for(auto y: g[x]) {
                if(las[x] < las[y]) {
                    ans -= (in[x] * out[x] + in[y] * out[y]) ;
                    in[x] --; out[x] ++; out[y] --; in[y] ++;
                    ans += (in[x] * out[x] + in[y] * out[y]) ;
                }
            }
        }
        las[x] = i;
        printf("%lld\n", ans);
    }
}