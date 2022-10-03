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
const int mod1=999999937,mod2=1000000009,MAX=300005,INF=1<<29;

ll rui1(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod1;
        a=a*a%mod1;
        b/=2;
    }
    return ans;
}

ll rui2(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod2;
        a=a*a%mod2;
        b/=2;
    }
    return ans;
}

ll g1[30],g2[30];

map<ll,int> MA;
vector<int> G[MAX];
ll ha1,ha2;
ll c[MAX];
string S;
set<pair<ll,ll>> SE[MAX];
ll a1[MAX],b1[MAX];
ll a2[MAX],b2[MAX];

ll f1(int u){
    return g1[S[u]-'a'];
}

ll f2(int u){
    return g2[S[u]-'a'];
}

void solve(int u,int p){
    SE[u].insert(mp(f1(u),f2(u)));
    for(int to:G[u]){
        if(to==p) continue;
        solve(to,u);
        if(si(SE[u])<si(SE[to])){
            swap(SE[u],SE[to]);
            swap(a1[u],a1[to]);
            swap(b1[u],b1[to]);
            swap(a2[u],a2[to]);
            swap(b2[u],b2[to]);
            a1[u]=a1[u]*ha1%mod1;
            b1[u]=(b1[u]*ha1%mod1+f1(u))%mod1;
            a2[u]=a2[u]*ha2%mod2;
            b2[u]=(b2[u]*ha2%mod2+f2(u))%mod2;
            for(pair<ll,ll> x:SE[to]){
                ll tx1=(a1[to]*x.fi%mod1+b1[to])%mod1;
                ll tx2=(a2[to]*x.se%mod2+b2[to])%mod2;
                SE[u].insert(mp((tx1-b1[u]+mod1)%mod1*rui1(a1[u],mod1-2)%mod1,(tx2-b2[u]+mod2)%mod2*rui2(a2[u],mod2-2)%mod2));
            }
        }else{
            for(pair<ll,ll> x:SE[to]){
                ll tx1=((a1[to]*x.fi%mod1+b1[to])%mod1*ha1%mod1+f1(u))%mod1;
                ll tx2=((a2[to]*x.se%mod2+b2[to])%mod2*ha2%mod2+f2(u))%mod2;
                SE[u].insert(mp((tx1-b1[u]+mod1)%mod1*rui1(a1[u],mod1-2)%mod1,(tx2-b2[u]+mod2)%mod2*rui2(a2[u],mod2-2)%mod2));
            }
        }
    }
    
    //SE[u].insert(((ll)(S[u]-'a')+1-b[u]+mod)*rui(a[u],mod-2)%mod);
    
    MA[si(SE[u])+c[u]]++;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    ha1=(ll)(rng()%mod1);
    ha2=(ll)(rng()%mod2);
    for(int i=0;i<26;i++){
        g1[i]=(ll)(rng()%mod1);
        g2[i]=(ll)(rng()%mod2);
    }
    int N;cin>>N;
    
    for(int i=0;i<N;i++) cin>>c[i];
    cin>>S;
    for(int i=0;i<N;i++){
        a1[i]=a2[i]=1;
        b1[i]=b2[i]=0;
    }
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    solve(0,-1);
    
    auto it=MA.rbegin();
    cout<<(*it).fi<<"\n";
    cout<<(*it).se<<"\n";
}