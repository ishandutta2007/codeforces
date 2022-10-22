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

const int N=1e6+99,lg=22;

int n,t,ans,a[N],dp[N];

void Main(){
	ans=0;
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1){
		dp[i]=0;
		int now=i;
		f(j,1,lg){
			int nxt=a[now]+(a[now]-a[i]);
			if(a[n]<nxt || now==n) break;
			now=lower_bound(a+now+1,a+1+n,nxt)-a;
			//cout<<now<<endl;
			maxm(ans,j+1);
			maxm(dp[i],j+1);
		}
		//cout<<endl;
	}
	f_(i,n-1,1){
		if(a[i]==a[i+1]){
			maxm(dp[i],dp[i+1]+1);
			maxm(ans,dp[i]);
		}
	}
	cout<<n-ans<<endl;
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}