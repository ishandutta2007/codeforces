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

const int N=1e6+99;

int n,t,e,ans,a[N],dp[N],prime[N];

void solve(vector<int> v){
	if(v.size()==0) return ;
	//cout<<"V : ";
	//f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl;
	int m=v.size();
	vector<int> p;
	f(i,0,m){
		dp[i]=0;
		if(v[i]!=1){
			ans--;
			p.pb(i);
		}
		if(p.size()==1) ans+=p[0]+1;
		else{
			if(p.size())
				ans+=p.back()-p[p.size()-2];
		}
	}
}
void Main(){
	ans=0;
	cin>>n>>e;
	f(i,0,n){
		cin>>a[i];
	}	
	f(i,0,e){
		vector<int> v;
		for(int j=i;j<n;j+=e){
			if(a[j]!=1 && !prime[a[j]]){
				solve(v);
				v.clear();
			}
			else{
				v.pb(a[j]);
			}
		}
		solve(v);
	}
	cout<<ans<<endl;
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f(i,2,N){
		prime[i]^=1;
		if(prime[i]){
			for(int j=i;j<N;j+=i){
				prime[j]=1;
			}
		}
	}
	cin>>t;
	while(t--){
		Main();
	}
}