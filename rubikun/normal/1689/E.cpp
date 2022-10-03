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
const int mod=998244353,MAX=2005,INF=1<<30;

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

void solve(){
    int N;cin>>N;
    vector<int> A(N);
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==0){
            A[i]++;
            ans++;
        }
    }
    
    UF uf;uf.init(N);
    for(int j=30;j>=0;j--){
        vector<int> X;
        for(int i=0;i<N;i++){
            if(A[i]&(1<<j)) X.push_back(i);
        }
        for(int i=0;i+1<si(X);i++) uf.unite(X[i],X[i+1]);
    }
    
    if(uf.size[uf.root(0)]==N){
        cout<<ans<<"\n";
        for(int a:A) cout<<a<<" ";
        cout<<"\n";
        return;
    }
    
    for(int k=0;k<N;k++){
        {
            A[k]++;
            UF uf;uf.init(N);
            for(int j=30;j>=0;j--){
                vector<int> X;
                for(int i=0;i<N;i++){
                    if(A[i]&(1<<j)) X.push_back(i);
                }
                for(int i=0;i+1<si(X);i++) uf.unite(X[i],X[i+1]);
            }
            
            if(uf.size[uf.root(0)]==N){
                cout<<ans+1<<"\n";
                for(int a:A) cout<<a<<" ";
                cout<<"\n";
                return;
            }
            A[k]--;
        }
        if(A[k]>=2){
            A[k]--;
            UF uf;uf.init(N);
            for(int j=30;j>=0;j--){
                vector<int> X;
                for(int i=0;i<N;i++){
                    if(A[i]&(1<<j)) X.push_back(i);
                }
                for(int i=0;i+1<si(X);i++) uf.unite(X[i],X[i+1]);
            }
            
            if(uf.size[uf.root(0)]==N){
                cout<<ans+1<<"\n";
                for(int a:A) cout<<a<<" ";
                cout<<"\n";
                return;
            }
            A[k]++;
        }
    }
    
    pair<int,int> ma=mp(-1,-1);
    for(int i=0;i<N;i++){
        for(int j=0;j<=30;j++){
            if(A[i]&(1<<j)){
                chmax(ma,mp(j,i));
                break;
            }
        }
    }
    
    ans++;
    A[ma.se]--;
    
    ma=mp(-1,-1);
    for(int i=0;i<N;i++){
        for(int j=0;j<=30;j++){
            if(A[i]&(1<<j)){
                chmax(ma,mp(j,i));
                break;
            }
        }
    }
    
    ans++;
    A[ma.se]++;
    
    cout<<ans<<"\n";
    for(int a:A) cout<<a<<" ";
    cout<<"\n";
    return;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        solve();
    }
}