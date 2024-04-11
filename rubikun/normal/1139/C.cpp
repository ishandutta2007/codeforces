#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int par[MAX],size[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
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


ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    ll ans=rui(N,K);
    init(N);
    
    for(int i=0;i<N-1;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        if(c==0) unite(a,b);
    }
    
    vector<int> used(N);
    
    for(int i=0;i<N;i++){
        if(used[root(i)]) continue;
        
        ans+=mod-rui(size[root(i)],K);
        ans%=mod;
        
        used[root(i)]=1;
    }
    
    cout<<ans<<endl;
}