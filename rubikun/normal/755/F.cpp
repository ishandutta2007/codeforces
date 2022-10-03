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
const int mod=1000000007,MAX=1000005;
const ll INF=1LL<<60;

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

bitset<MAX> dp;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    UF uf;uf.init(N);
    vector<int> cnt(N+1);
    for(int i=0;i<N;i++){
        int x;cin>>x;x--;
        uf.unite(i,x);
    }
    vector<int> S;
    
    for(int i=0;i<N;i++){
        if(uf.root(i)==i){
            cnt[uf.size[i]]++;
            S.push_back(uf.size[i]);
        }
    }
    sort(all(S));
    
    for(int i=1;i<=N;i++){
        if(cnt[i]>=3){
            int can=(cnt[i]-1)/2;
            cnt[i*2]+=can;
            cnt[i]-=can*2;
        }
    }
    
    dp[0]=true;
    for(int i=1;i<=N;i++){
        for(int j=0;j<cnt[i];j++){
            dp|=(dp<<i);
        }
    }
    
    int ma=0,rem=K;
    for(int a:S){
        if(rem){
            int can=min(a/2,rem);
            ma+=can*2;
            rem-=can;
        }
    }
    if(rem){
        ma+=rem;
        chmin(ma,N);
    }
    
    int mi;
    
    if(dp[K]) mi=K;
    else mi=K+1;
    
    cout<<mi<<" "<<ma<<endl;
    
    
    
}