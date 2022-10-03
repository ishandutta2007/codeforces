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
const int mod=998244353,MAX=105,INF=1<<30;

//Union Find

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<ll,ll>> A(N);
    set<pair<ll,int>> SE;
    
    for(int i=0;i<N;i++){
        cin>>A[i].fi>>A[i].se;
    }
    
    sort(all(A),[](auto a,auto b){
        return a.fi+a.se>b.fi+b.se;
    });
    
    for(int i=0;i<N;i++){
        SE.insert(mp(A[i].fi,i));
    }
    
    UF uf;
    uf.init(N);
    
    ll ans=0;
    
    for(int i=N-1;i>=1;i--){
        auto it=SE.begin();
        while(uf.check(i,(*it).se)) it++;
        uf.unite(i,(*it).se);
        ans+=max((*it).fi-A[i].fi,A[i].se);
        
        //cout<<i<<" "<<(*it).se<<endl;
        SE.erase(it);
    }
    
    ans+=A[0].se;
    
    cout<<ans<<endl;
}