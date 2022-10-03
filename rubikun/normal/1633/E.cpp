#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=1005;
const ll INF=1LL<<60;

struct UF{
    int n;
    vector<int> par,size,edge;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        edge[root(a)]++;
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            edge[root(a)]+=edge[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

struct edge{
    int from;
    int to;
    int cost;
    int id;
};

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<edge> S(M);
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        S[i]={a,b,c,i};
    }
    sort(all(S),[](auto a,auto b){
        return a.cost<b.cost;
    });
    
    vector<ll> use;
    use.push_back(-1);
    use.push_back(100000001);
    for(int i=0;i<M;i++){
        for(int j=i+1;j<M;j++){
            ll k=(S[i].cost+S[j].cost)/2;
            use.push_back(k-1);
            use.push_back(k);
            use.push_back(k+1);
        }
        use.push_back(S[i].cost-1);
        use.push_back(S[i].cost);
        use.push_back(S[i].cost+1);
    }
    sort(all(use));
    use.erase(unique(all(use)),use.end());
    
    vector<pair<ll,vector<ll>>> T;
    
    for(ll e:use){
        UF uf;uf.init(N);
        sort(all(S),[&](auto a,auto b){
            ll x=abs(a.cost-e),y=abs(b.cost-e);
            return x<y;
        });
        
        ll suml=0,sumr=0,cnl=0;
        for(int i=0;i<M;i++){
            if(uf.check(S[i].from,S[i].to)) continue;
            uf.unite(S[i].from,S[i].to);
            if(S[i].cost<=e){
                suml-=S[i].cost;
                cnl++;
            }else{
                sumr+=S[i].cost;
                cnl--;
            }
        }
        
        T.push_back(mp(e,vector<ll>{suml,sumr,cnl}));
        
        //cout<<e<<" "<<suml<<" "<<sumr<<" "<<cnl<<endl;
    }
    
    int p,Q;ll a,b,c;cin>>p>>Q>>a>>b>>c;
    vector<ll> que(Q);
    for(int q=0;q<p;q++) cin>>que[q];
    for(int i=p;i<Q;i++){
        que[i]=(que[i-1]*a+b)%c;
    }
    sort(all(que));
    ll ans=0;
    auto it=T.begin();
    for(int q=0;q<Q;q++){
        ll e=que[q];
        while((*it).fi<e) it++;
        ll suml=(*it).se[0],sumr=(*it).se[1],cn=(*it).se[2];
        ans^=(suml+sumr+cn*e);
    }
    cout<<ans<<"\n";
}