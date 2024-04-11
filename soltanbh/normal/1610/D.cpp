#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99,mod=1e9+7,lg=32;

int n,t,ans,od,z,a[N],b[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		if(a[i]%2==0){
			z++;
			int x=a[i],cnt=0;
			while(x%2==0){
				cnt++;
				x/=2;
			}
			b[cnt]++;
		}
		else{
			od++;
		}
	}
	ans=(pow(2,od,mod)-1)*pow(2,z,mod)%mod;
	f_(i,lg,0){
		b[i+1]+=b[i+2];
		if(b[i]){
			int res=(pow(2,b[i]-1,mod)-1+mod)%mod;	Add(ans,res*pow(2,b[i+1],mod)%mod);
		}
	}
	cout<<ans;
}