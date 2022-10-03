#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

int par[MAX],siz[MAX];
bool cycle[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        siz[i]=1;
        cycle[i]=0;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        cycle[root(a)]|=cycle[root(b)];
        siz[root(a)]+=siz[root(b)];
        par[root(b)]=root(a);
    }
}

bool check(int a,int b){
    return root(a)==root(b);
}

struct dataa{
    int x;
    int y;
    int id;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    init(N);
    vector<dataa> S(N);
    
    for(int i=0;i<N;i++){
        cin>>S[i].x>>S[i].y;
        S[i].id=i;
    }
    
    sort(all(S),[](auto a,auto b){
        return a.x<b.x;
    });
    
    for(int i=0;i+1<N;i++){
        if(S[i].x==S[i+1].x){
            if(check(S[i].id,S[i+1].id)) cycle[root(S[i].id)]=1;
            unite(S[i].id,S[i+1].id);
        }
    }
    
    sort(all(S),[](auto a,auto b){
        return a.y<b.y;
    });
    
    for(int i=0;i+1<N;i++){
        if(S[i].y==S[i+1].y){
            if(check(S[i].id,S[i+1].id)) cycle[root(S[i].id)]=1;
            unite(S[i].id,S[i+1].id);
        }
    }
    
    ll ans=1;
    
    vector<set<int>> X(N),Y(N);
    
    for(int i=0;i<N;i++){
        X[root(S[i].id)].insert(S[i].x);
        Y[root(S[i].id)].insert(S[i].y);
    }
    
    for(int i=0;i<N;i++){
        if(root(i)!=i) continue;
        
        if(cycle[i]){
            ans*=rui(2,X[i].size()+Y[i].size());
            ans%=mod;
        }else{
            ans*=(rui(2,X[i].size()+Y[i].size())-1);
            ans%=mod;
        }
    }
    
    cout<<ans<<endl;
    
}