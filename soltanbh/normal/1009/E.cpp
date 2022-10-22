#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=1e6+9,mod=998244353;
int a[N],n;
ll ans=0,p,tvn[N];
int main(){
	tvn[0]=1;
	f(i,1,N) tvn[i]=tvn[i-1]*2ll%mod;
	cin>>n;
	f(i,0,n) gett(a[i]);
	f(i,1,n+1){
		p=(n-i)*tvn[n-1-i]%mod;
		p=(p+tvn[n-i])%mod;
		ans=(ans+p*a[i-1])%mod;
	}
	cout<<ans;
}