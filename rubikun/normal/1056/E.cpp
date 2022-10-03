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
const int mod1=999999893,mod2=999999929,MAX=200005,INF=1<<30;

struct Rollinghash{
    string S;
    int n;
    int base1;
    int base2;
    vector<ll> h1,h2,ru1,ru2;
    
    void make(string &T,int ba1,int ba2){
        S=T;
        n=S.size();
        h1.assign(n+1,0);
        h2.assign(n+1,0);
        ru1.assign(n+1,0);
        ru2.assign(n+1,0);
        base1=ba1;
        base2=ba2;
        
        ru1[0]=1;
        ru2[0]=1;
        
        for(int i=1;i<=n;i++){
            h1[i]=h1[i-1]*base1+ll(S[i-1]-'A');
            h1[i]%=mod1;
            
            h2[i]=h2[i-1]*base2+ll(S[i-1]-'A');
            h2[i]%=mod2;
            
            ru1[i]=ru1[i-1]*base1%mod1;
            ru2[i]=ru2[i-1]*base2%mod2;
        }
    }
    
    pair<ll,ll> ha(int l,int r){
        pair<ll,ll> res;
        res.fi=(h1[r]-h1[l]*ru1[r-l]%mod1+mod1)%mod1;
        res.se=(h2[r]-h2[l]*ru2[r-l]%mod2+mod2)%mod2;
        
        return res;
    }//
};


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937_64 rng(58);
    
    string S,T;cin>>S>>T;
    
    ll M=si(T);
    
    ll ha1=rng()%mod1,ha2=rng()%mod2;
    
    ll a=0,b=0;
    
    for(char c:S){
        if(c=='0') a++;
        else b++;
    }
    
    Rollinghash ro;
    ro.make(T,ha1,ha2);
    
    int ans=0;
    
    for(ll x=1;x<=M;x++){
        ll y=(M-x*a)/b;
        if(x*a+y*b!=M) continue;
        if(y<=0) continue;
        
        pair<ll,ll> s=mp(-1,-1),t=mp(-1,-1);
        
        bool ok=true;
        
        int now=0;
        for(char c:S){
            if(c=='0'){
                if(s.fi==-1) s=ro.ha(now,now+x);
                else ok&=(s==ro.ha(now,now+x));
                now+=x;
            }else{
                if(t.fi==-1) t=ro.ha(now,now+y);
                else ok&=(t==ro.ha(now,now+y));
                now+=y;
            }
        }
        
        ok&=(s!=t);
        
        if(ok) ans++;
    }
    
    cout<<ans<<endl;
}