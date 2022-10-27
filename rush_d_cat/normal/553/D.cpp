#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N=100000+10;
typedef long long LL;
int n,m,k;
int bu[N],deg[N],has[N]; vector<int> g[N];
double rate[N];
struct Nod{
    LL a,b;int id;
    bool operator<(const Nod&o)const{
        if(a*o.b == o.a*b) return id<o.id;
        return a*o.b<o.a*b;
    }
    void prt(){
        printf("a=%lld, b=%lld, id=%d\n", a,b,id);
    }
};
set<Nod> st; vector<int> laji;
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++){
        int x; scanf("%d",&x); bu[x]=1; 
    }
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        deg[u]++, deg[v]++;
        g[u].push_back(v); g[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(bu[i]==0) {
            for(auto v:g[i]){
                if(bu[v]==0)has[i]++;
            }
            st.insert((Nod){has[i],deg[i],i});
        } else {
            laji.push_back(i);
        }
    }

    double ans=0; int bst=laji.size(); // [0,bst)

    while(st.size()){

        Nod now=*st.begin(); st.erase(now); 
        //now.prt();
        //printf("# %d %d\n", now.a, now.b);
        if(bu[now.id])continue;
        int u=now.id; bu[u]=1;

        if(1.0*now.a/now.b > ans){
            ans=1.0*now.a/now.b; bst=laji.size();
        }
        laji.push_back(now.id);
        
        for(auto v:g[u]){
            if(bu[v]==1)continue;
            st.erase((Nod){has[v],deg[v],v});
            has[v]--;
            //printf("v=%d, has=%d\n", v,has[v]);
            st.insert((Nod){has[v],deg[v],v});
        }
    }
    vector<int> ret;
    for(int i=1;i<=n;i++) bu[i]=0;
    for(int i=0;i<bst;i++)bu[laji[i]]=1;
    for(int i=1;i<=n;i++)if(bu[i]==0)ret.push_back(i);
    //if(n>=5000)printf("%.5f\n", ans);
    printf("%d\n", ret.size());
    for(auto x: ret) printf("%d ", x);
}