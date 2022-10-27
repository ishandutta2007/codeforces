#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 100000+10;
int n,m,k,x[N],u[N],v[N],w[N];
int par[N];

int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
bool check(int K) {
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<=m;i++){
        if(w[i]<=K) par[find(u[i])]=find(v[i]);
    }
    set<int> st;
    for(int i=1;i<=k;i++){
        st.insert(find(x[i]));
    }
    return st.size() <= 1;
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&x[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    }
    int L=0,R=1e9;
    while(R-L>1) {
        int mid=(L+R)>>1;
        if(check(mid)) R=mid; else L=mid;
    }
    for(int i=1;i<=k;i++) printf("%d ", R);
}