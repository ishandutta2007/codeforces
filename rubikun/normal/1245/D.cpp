#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2005,INF=1<<30;

int par[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)) par[root(b)]=root(a);
}

bool check(int a,int b){
    return root(a)==root(b);
}

struct edge{
    int from;
    int to;
    ll cost;
};

bool compare(edge a,edge b){
    return a.cost<b.cost;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    init(N+1);
    vector<ll> X(N),Y(N),C(N);
    
    for(int i=0;i<N;i++){
        //cin>>X[i]>>Y[i];
        scanf("%lld%lld",&X[i],&Y[i]);
    }
    
    vector<edge> E;
    
    for(int i=0;i<N;i++){
        ll a;
        //cin>>a;
        scanf("%lld",&a);
        E.push_back({0,i+1,a});
    }
    
    for(int i=0;i<N;i++){
        ll c;
        //cin>>c;
        scanf("%lld",&c);
        C[i]=c;
    }
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            E.push_back({i+1,j+1,(abs(X[i]-X[j])+abs(Y[i]-Y[j]))*(C[i]+C[j])});
        }
    }
    
    sort(all(E),compare);
    
    ll ans=0;
    
    vector<int> usever;
    vector<pair<int,int>> useedge;
    
    for(edge e:E){
        int a=e.from,b=e.to;
        ll c=e.cost;
        
        if(check(a,b)) continue;
        unite(a,b);
        ans+=c;
        
        if(a==0) usever.push_back(b);
        else useedge.push_back({a,b});
    }
    
    cout<<ans<<endl;
    
    cout<<usever.size()<<endl;
    
    if(usever.size()){
        for(int i=0;i<usever.size();i++){
            if(i){
                //cout<<" ";
                printf(" ");
            }
            //cout<<usever[i];
            printf("%d",usever[i]);
        }
        //cout<<endl;
        printf("\n");
    }
    
    cout<<useedge.size()<<endl;
    
    if(useedge.size()){
        for(int i=0;i<useedge.size();i++){
            //cout<<useedge[i].first<<" "<<useedge[i].second<<endl;
            printf("%d",useedge[i].first);
            printf(" ");
            printf("%d\n",useedge[i].second);
        }
    }
    
    
}