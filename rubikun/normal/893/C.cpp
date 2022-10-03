#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;
const ll INF=1LL<<60;

int par[MAX];
ll mini[MAX],cost[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        mini[i]=cost[i];
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        mini[root(a)]=min(mini[root(a)],mini[root(b)]);
        par[root(b)]=root(a);
    }
}

bool check(int a,int b){
    return root(a)==root(b);
}

int main(){
    
    int N,M;cin>>N>>M;
    
    for(int i=0;i<N;i++){
        //cin>>cost[i];
        scanf("%lld",&cost[i]);
    }
    
    init(N);
    
    for(int i=0;i<M;i++){
        int a,b;
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        a--;b--;
        unite(a,b);
    }
    
    set<pair<int,int>> SE;
    
    for(int i=0;i<N;i++){
        SE.insert({root(i),mini[root(i)]});
    }
    
    ll ans=0;
    
    for(auto it=SE.begin();it!=SE.end();it++){
        ans+=(*it).second;
    }
    
    cout<<ans<<endl;
    
    
    
}