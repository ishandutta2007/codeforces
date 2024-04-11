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
const int mod=998244353,MAX=400005;
const int INF=1<<30;

ll inv[MAX],fac[MAX],finv[MAX];

void make(){
    
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    
    for(int i=2;i<MAX;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll)i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
    
}

ll comb(ll a,ll b){
    if(a<0||b<0) return 0;
    if(a<b) return 0;
    return fac[a]*(finv[b]*finv[a-b]%mod)%mod;
}

ll perm(ll a,ll b){
    if(a<0||b<0) return 0;
    if(a<b) return 0;
    return fac[a]*finv[a-b]%mod;
}

int cnt[MAX];
ll rui[MAX][43];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    make();
    
    int N,M;cin>>N>>M;
    vector<pair<int,int>> S(N),T(M);
    for(int i=0;i<N;i++){
        cin>>S[i].fi>>S[i].se;
        cnt[S[i].fi]++;
        cnt[S[i].se+1]--;
    }
    for(int i=0;i<M;i++){
        cin>>T[i].fi>>T[i].se;
        T[i].fi--;T[i].se--;
    }
    
    for(int i=1;i<=N;i++) cnt[i]+=cnt[i-1];
    
    ll ans=0;
    
    for(int j=0;j<=40;j++){
        for(int i=1;i<=N;i++){
            rui[i][j]=rui[i-1][j]+comb(cnt[i]-j,i-j);
            rui[i][j]%=mod;
        }
    }
    
    for(int bit=0;bit<(1<<M);bit++){
        int l=1,r=N;
        set<int> SE;
        for(int i=0;i<M;i++){
            if(bit&(1<<i)){
                int a=T[i].fi,b=T[i].se;
                chmax(l,S[a].fi);
                chmin(r,S[a].se);
                chmax(l,S[b].fi);
                chmin(r,S[b].se);
                SE.insert(a);
                SE.insert(b);
            }
        }
        int k=__builtin_popcount(bit);
        chmax(l,si(SE));
        if(l<=r){
            if(k&1) ans+=ll(mod)-(rui[r][si(SE)]-rui[l-1][si(SE)]);
            else ans+=ll(mod)+(rui[r][si(SE)]-rui[l-1][si(SE)]);
            
            ans%=mod;
        }
        
        //cout<<bit<<" "<<l<<" "<<r<<endl;
    }
    
    cout<<ans<<endl;
}