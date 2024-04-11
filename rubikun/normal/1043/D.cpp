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
const int mod1=1000000007,mod2=1000000009,MAX=100005,INF=1<<30;

struct Rollinghash{
    vector<ll> S;
    int n;
    int base1;
    int base2;
    vector<ll> h1,h2,ru1,ru2;
    
    void make(vector<ll> &T,int ba1,int ba2){
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
            h1[i]=h1[i-1]*base1+S[i-1];
            h1[i]%=mod1;
            
            h2[i]=h2[i-1]*base2+S[i-1];
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

int pos[MAX][10];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);

    mt19937_64 rng(58);
    int ba1=rng(),ba2=rng();
    
    int N,M;cin>>N>>M;
    
    vector<Rollinghash> X(M);
    
    for(int i=0;i<M;i++){
        vector<ll> A(N);
        for(int j=0;j<N;j++){
            cin>>A[j];
            A[j]--;
            pos[A[j]][i]=j;
        }
        X[i].make(A,ba1,ba2);
    }
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        int ma=0;
        for(int j=0;j<M;j++) chmax(ma,pos[i][j]);
        int left=1,right=N-ma+1;
        
        while(right-left>1){
            int mid=(left+right)/2;
            
            bool ok=true;
            
            ll a=-1,b=-1;
            
            for(int j=0;j<M;j++){
                auto p=X[j].ha(pos[i][j],pos[i][j]+mid);
                if(j==0){
                    a=p.fi;
                    b=p.se;
                }else{
                    if(a!=p.fi||b!=p.se) ok=false;
                }
            }
            
            if(ok) left=mid;
            else right=mid;
        }
        
        ans+=left;
    }
    
    cout<<ans<<endl;
    
}