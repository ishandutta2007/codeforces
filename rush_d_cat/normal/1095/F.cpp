#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,m,par[N]; 
LL a[N],minv[N];multiset< pair<LL,int> > st;
struct Edge {
    int u,v; LL w;
    bool operator<(const Edge&o)const{
        return w<o.w;
    }
    void read() {
        scanf("%d%d%lld",&u,&v,&w);
    }
} e[N];

int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
int main(){
    for(int i=0;i<N;i++)par[i]=i;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);minv[i]=a[i];
        st.insert(make_pair(a[i],i));
    }
    for(int i=1;i<=m;i++){
        e[i].read();
    }
    sort(e+1,e+1+m);
    int low=1; LL ans=0;
    for(int i=1;i<n;i++){
        while(low <= m && find(e[low].u) == find(e[low].v)) ++ low;
        
        pair<LL,int> e1 = *st.begin(); st.erase(st.find(e1));
        pair<LL,int> e2 = *st.begin(); st.erase(st.find(e2));

        LL temp = e1.first + e2.first;
        if(low<=m && temp>e[low].w) { 
            ans += e[low].w;
            st.insert(e1); st.insert(e2);
            int pu = find(e[low].u);
            int pv = find(e[low].v);
            st.erase(st.find(make_pair(minv[pu],pu))); 
            st.erase(st.find(make_pair(minv[pv],pv)));
            minv[pv] = min(minv[pv],minv[pu]);
            par[pu] = pv;
            st.insert(make_pair(minv[pv],pv)); low++;
        } else {
            ans += temp;
            minv[find(e2.second)] = min(minv[find(e1.second)], minv[find(e2.second)]);
            par[find(e1.second)] = find(e2.second);
            st.insert(make_pair(minv[find(e2.second)], find(e2.second)));
        }
    }
    cout<<ans<<endl;
}