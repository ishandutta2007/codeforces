#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2000 + 10;
int n;
vector<int> g[N],leaf[N];
int sum[N],deg[N];


int gen(int u,int p){
    if(deg[u]==1) {
        return u;
    }
    for(auto v: g[u]) {
        if(p==v)continue;
        return gen(v,u);
    }
}

int u[N],v[N],w[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        g[u[i]].push_back(v[i]); g[v[i]].push_back(u[i]);
        deg[u[i]]++, deg[v[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]==2) {
            return !printf("NO\n");
        }
    }
    printf("YES\n");
    if(n==2) {
        printf("1\n");
        printf("1 2 %d\n",w[1]);
        return 0;
    }
    int cnt = 0;
    for(int i=1;i<n;i++){
        if(deg[u[i]]>=3 && deg[v[i]]>=3) cnt += 4;
        else cnt += 3;
    }
    printf("%d\n", cnt);
    for(int i=1;i<n;i++){
        std::vector<int> v1,v2;
        if(deg[u[i]]>=3 && deg[v[i]]>=3) {
            
            for(auto x: g[u[i]]) {
                if(x==v[i]) continue;
                v1.push_back(gen(x, u[i]));
                if(v1.size()==2) break;
            }
            for(auto x: g[v[i]]) {
                if(x==u[i]) continue;
                v2.push_back(gen(x, v[i]));
                if(v2.size()==2) break;
            }
            printf("%d %d %d\n", v1[0],v2[0],w[i]/2);
            printf("%d %d %d\n", v1[1],v2[1],w[i]/2);
            printf("%d %d %d\n", v1[0],v1[1],-w[i]/2);
            printf("%d %d %d\n", v2[0],v2[1],-w[i]/2);
        } else {
            if (deg[u[i]] == 1) swap(u[i], v[i]);
            for(auto x: g[u[i]]) {
                if(x==v[i]) continue;
                v1.push_back(gen(x, u[i]));
                if(v1.size()==2) break;
            }
            printf("%d %d %d\n", v[i],v1[0],w[i]/2);
            printf("%d %d %d\n", v[i],v1[1],w[i]/2);
            printf("%d %d %d\n", v1[0],v1[1],-w[i]/2);
        }
    }
}