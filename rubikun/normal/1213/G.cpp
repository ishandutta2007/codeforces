#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200001,INF=1<<30;
struct edge{int u,v,w;};
bool compare(edge a,edge b){
    if(a.w==b.w) return a.u<b.u;
    return a.w<b.w;
}

int par[MAX];
ll size[MAX];

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

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    init(N);
    
    vector<edge> S(N-1);
    for(int i=0;i<N-1;i++){
        int a,b,c;cin>>a>>b>>c;
        S[i]={a,b,c};
    }
    sort(all(S),compare);
    S.push_back({0,0,INF});
    
    vector<ll> ans(MAX,0);
    int j=0;
    
    for(int i=1;i<MAX;i++){
        ans[i]=ans[i-1];
        while(S[j].w==i){
            int a=S[j].u,b=S[j].v;
            if(!check(a,b)){
                ans[i]-=size[root(a)]*(size[root(a)]-1)/2;
                ans[i]-=size[root(b)]*(size[root(b)]-1)/2;
                unite(a,b);
                ans[i]+=size[root(a)]*(size[root(a)]-1)/2;
            }
            j++;
        }
    }
    
    for(int i=0;i<M;i++){
        int a;cin>>a;
        if(i) cout<<" ";
        cout<<ans[a];
    }
    
    cout<<endl;
}