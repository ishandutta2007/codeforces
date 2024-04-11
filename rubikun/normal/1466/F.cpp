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
    vector<int> par,size,ok,mi;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        ok.assign(n,0);
        mi.assign(n,INF);
        
        for(int i=0;i<n;i++){
            par[i]=i;
            mi[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            ok[root(a)]|=ok[root(b)];
            mi[root(a)]=min(mi[root(a)],mi[root(b)]);
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
    
    int N,M;cin>>N>>M;
    UF uf;
    uf.init(M);
    
    vector<int> ans;
    
    for(int i=0;i<N;i++){
        int k;cin>>k;
        if(k==1){
            int a;cin>>a;
            a--;
            
            if(!uf.ok[uf.root(a)]){
                ans.push_back(i);
                uf.ok[uf.root(a)]=1;
            }
        }else{
            int a,b;cin>>a>>b;
            a--;b--;
            
            if(!uf.check(a,b)&&(!uf.ok[uf.root(a)]||!uf.ok[uf.root(b)])){
                ans.push_back(i);
            }
            uf.unite(a,b);
        }
    }
    
    ll res=1;
    
    for(int i=0;i<si(ans);i++){
        res*=2;
        res%=mod;
    }
    
    cout<<res<<" "<<si(ans)<<endl;
    for(int a:ans) cout<<a+1<<" ";
    cout<<endl;
}