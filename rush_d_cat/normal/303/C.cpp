#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
const int N = 5002;
int a[N],n,k,c[1000002],d[1000002];
pair<int,int> v[1000002][6]; int tot[10000002];
int par[N],sz[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
bool can(vector< pair<int,int> > vec) {
    for(auto p: vec) {
        par[p.first]=p.first; sz[p.first]=1;
        par[p.second]=p.second; sz[p.second]=1;
        //printf("edge: %d-%d\n", p.first,p.second);
    }
    for(auto p: vec) {
        if(find(p.first) != find(p.second)) {
            sz[find(p.second)] += sz[find(p.first)];
            par[find(p.first)] = find(p.second);
        }
    }
    unordered_set<int> st; for(auto p: vec) st.insert(p.first), st.insert(p.second);
    int ans=st.size();
    for(auto x: st) {
        if(find(x)==x) {
            ans--;
        }
    }
    return ans<=k;
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)c[a[j]-a[i]]++;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(c[a[j]-a[i]]<=5){
        v[a[j]-a[i]][++tot[a[j]-a[i]]] = make_pair(i,j);
    }
    for(int i=1;i<=1000000;i++){
        vector< pair<int,int> > tmp;
        int ok=1,s=0;
        for(int j=i;j<=1000000;j+=i){
            if(c[j]>5) ok=0;
            s+=c[j];
            if(s>10) ok=0;
        }
        if(!ok) continue;
        for(int j=i;j<=1000000;j+=i){
            for(int k=1;k<=tot[j];k++) tmp.push_back(v[j][k]);
        }
        //printf("i=%d, c=%d\n", i, c[i]);
        if(can(tmp)) return !printf("%d\n", i);
    }
}