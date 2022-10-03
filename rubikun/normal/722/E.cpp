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
const int mod=1000000007,MAX=400005;
const ll INF=1LL<<60;

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
    if(a<b) return 0;
    return fac[a]*(finv[b]*finv[a-b]%mod)%mod;
}

ll perm(ll a,ll b){
    if(a<b) return 0;
    return fac[a]*finv[a-b]%mod;
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

ll dp[2005][40];
ll ruii[40];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    make();
    int H,W,N,s;cin>>H>>W>>N>>s;
    H--;W--;
    
    vector<pair<int,int>> S(N);
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[i]=mp(a,b);
    }
    S.push_back(mp(0,0));
    S.push_back(mp(H,W));
    
    sort(all(S));
    
    N+=2;
    
    dp[0][0]=1;
    for(int i=1;i<N;i++){
        for(int j=1;j<=35;j++){
            ll sum=comb(S[i].fi+S[i].se,S[i].fi);
            for(int k=0;k<j;k++){
                sum+=mod-dp[i][k];
                sum%=mod;
            }
            for(int t=0;t<i;t++){
                int dh=S[i].fi-S[t].fi,dw=S[i].se-S[t].se;
                if(dh<0||dw<0) continue;
                if(j==35) continue;
                sum+=mod-dp[t][j]*comb(dh+dw,dh)%mod;
                sum%=mod;
            }
            dp[i][j]=sum;
        }
    }
    
    ll ans=0;
    
    ruii[0]=s;
    for(int i=1;i<40;i++){
        ruii[i]=ruii[i-1]-ruii[i-1]/2;
    }
    
    for(int j=1;j<=35;j++){
        ans+=dp[N-1][j]*ruii[j-1]%mod;
        ans%=mod;
    }
    
    ans*=rui(comb(H+W,H),mod-2);
    ans%=mod;
    
    cout<<ans<<endl;
}