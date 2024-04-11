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
const int mod=1000000007,MAX=200005,INF=1<<30;

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

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    UF uf;
    uf.init(N);
    vector<int> cnt(N);
    for(int i=0;i<N;i++){
        int a;cin>>a;
        a--;
        cnt[a]++;
        if(cnt[a]>=2){
            cout<<-1<<endl;
            return 0;
        }
        uf.unite(i,a);
    }
    
    set<int> SE;
    for(int i=0;i<N;i++){
        if(uf.root(i)==i){
            if(uf.size[i]&1) SE.insert(uf.size[i]);
            else SE.insert(uf.size[i]/2);
        }
    }
    
    ll ans=1;
    
    for(int a:SE){
        ll g=gcd(ans,a);
        ans=ans*a/g;
    }
    
    cout<<ans<<endl;
    
}