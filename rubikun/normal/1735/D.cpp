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
const int mod=998244353,MAX=300005,INF=1<<30;

//Union Find


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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<vector<int>> S(N,vector<int>(K));
    for(int i=0;i<N;i++) for(int j=0;j<K;j++) cin>>S[i][j];
    
    sort(all(S));
    
    map<vector<int>,ll> MA;
    
    for(int a=0;a<N;a++){
        for(int b=a+1;b<N;b++){
            vector<int> A(K);
            for(int j=0;j<K;j++){
                A[j]=(6-S[a][j]-S[b][j])%3;
            }
            MA[A]++;
        }
    }
    
    ll ans=0;
    
    for(auto a:MA){
        if(a.se>=2){
            if(binary_search(all(S),a.fi)) ans+=a.se*(a.se-1)/2;
        }
    }
    
    cout<<ans<<endl;
}