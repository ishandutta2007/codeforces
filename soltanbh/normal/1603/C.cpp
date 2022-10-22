#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+99,mod=998244353;

int n,t,res,ans,a[N],b[N];

int s(int x,int y){
	return (x+y-1)/y;
}
void solve(int x){
	if(x==0) return ;
	int mv,y=a[x+1]/b[x+1];
	if(s(a[x],b[x])<=a[x+1]/b[x+1]) return ;
	mv=s(a[x],y);
	//cout<<mv<<" "<<b[x]<<endl;
	Add(res,1ll*x*(mv-b[x])%mod);
	b[x]=mv;
	//eror(res);
	solve(x-1);
}
void Main(){
	ans=res=0;
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1){
		b[i]=1;
		solve(i-1);
		Add(ans,res);
		//f(j,1,i+1) cout<<b[j]<<" "; cout<<endl;
		
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
		Main();
}