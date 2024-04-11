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

const int N=5e5+9,mod=1e9+7;

ll t,n,q,l,r,t0[N],t1[N],a[N];
string s;

void calc(int p0,int p1){
	ll ans=0;
	ans=(p1+a[p1+p0-1]+mod-a[max(p0-1,0)])%mod;
	cout<<ans<<endl;
}
int main(){
	f(i,1,N)
		a[i]=(a[i-1]*2ll+1)%mod;
	f(i,1,N)
		a[i]=(a[i-1]+a[i])%mod;
	cin>>n>>q;
	cin>>s;
	s=' '+s;
	f(i,1,n+1)
		t0[i]=t0[i-1]+(s[i]=='0'),t1[i]=i-t0[i];
	f(i,0,q){
		cin>>l>>r;
		--l;
		calc(t0[r]-t0[l],t1[r]-t1[l]);
	}
}