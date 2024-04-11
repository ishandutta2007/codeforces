#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,mod=998244353;

int n,t,dp[N];
string s;

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

int main(){
    cin>>t;
    while(t--){
        int cnt=0,t1=0,t0=0,ans=1;
        cin>>n>>s;
        s=' '+s;
        f(i,1,n+1){
            if(s[i]=='1') cnt++;
            else cnt=0,t0++;
            if((i==n || s[i+1]=='0')) t1+=cnt/2;
        }
        f(i,1,t1+1) ans=1ll*ans*pow(i,mod-2,mod)%mod;
        f_(i,t1+t0,t0+1) ans=1ll*ans*i%mod;
        cout<<ans<<endl;
    }
}