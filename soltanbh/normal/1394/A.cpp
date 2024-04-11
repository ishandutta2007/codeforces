#include <bits/stdc++.h>
#include <iostream>
using namespace std;
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
#define int ll

const int N=1e5+99;

int n,t,d,p,m,a[N],b[N];
ll ans;

main(){
	ll res=0;
	cin>>n>>d>>m;
	f(i,0,n)
		get(a[i]);
	sort(a,a+n);
	p=n;
	f(i,0,n){
		if(a[i]<=m)
			res+=a[i];
		else
			minm(p,i);
	}
	maxm(ans,res);
	f(i,1,n+1)
		b[i]=b[i-1]+a[i-1];
	for(int i=1;a[n-i]>m && i<=(n+d)/(d+1);i++){
		int u=max(i-1,0ll)*d;
		u=max(0ll,u-(n-i-p));
		res+=a[n-i];
		maxm(ans,res-b[u]);
	}
	cout<<ans;
}