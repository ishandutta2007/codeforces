#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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
const int N=3e5+99,mod=998244353;
int n,t,x,e1=1,e2=1,a[N],ans,fac[N],mark1[N],mark2[N],mn[N],mx[N],k=1;
pair<int,int> p[N];
map<pair<int,int> ,int> mapp; 
int main(){
	fac[0]=1;
	f(i,1,N) fac[i]=(1ll*fac[i-1]*i)%mod;
	cin>>n;
	f(i,0,n){
		cin>>p[i].F>>p[i].S;
		mapp[p[i]]++;
		maxm(mx[p[i].F],p[i].S);
		mark1[p[i].S]++,mark2[p[i].F]++;
	}
	f(i,1,n+1){
		e1=(1ll*e1*fac[mark1[i]])%mod;
		e2=(1ll*e2*fac[mark2[i]])%mod;
	}
	ans=(e1+e2)%mod,e1=1;
	f(i,0,n){
		e1=1ll*e1*fac[mapp[p[i]]]%mod;
		mapp[p[i]]=0;
	}
	sort(p,p+n);
	f(i,1,n+1){
		mx[i]=max(mx[i-1],mx[i]);
	}
	f(i,0,n){
		if(p[i].S<mx[p[i].F-1])
			k=0;
	}
	if(k)
		ans=(ans+mod-e1)%mod;
	cout<<(fac[n]+mod-ans)%mod;
}