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
const int mod1=998244353,mod2=1000000009,MAX=300005;
const ll INF=1LL<<61;

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
            h1[i]=h1[i-1]*base1+ll(S[i-1]-'a');
            h1[i]%=mod1;
            
            h2[i]=h2[i-1]*base2+ll(S[i-1]-'a');
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

const int mod=1000000007;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    string T;cin>>T;
    string S(N,'~');
    vector<int> A(M);
    for(int i=0;i<M;i++){
        cin>>A[i];A[i]--;
    }
    sort(all(A));
    reverse(all(A));
    
    for(int a:A){
        for(int j=a;j<a+si(T);j++){
            if(S[j]=='~') S[j]=T[j-a];
            else break;
        }
    }
    
    bool f=true;
    
    Rollinghash ro1,ro2;
    ro1.make(S,127,137);
    ro2.make(T,127,137);
    
    for(int a:A){
        f&=(ro1.ha(a,a+si(T))==ro2.ha(0,si(T)));
    }
    
    if(f){
        ll ans=1;
        for(char c:S){
            if(c=='~'){
                ans*=26;
                ans%=mod;
            }
        }
        cout<<ans<<endl;
    }else{
        cout<<0<<endl;
    }
}