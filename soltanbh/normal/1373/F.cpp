#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,l,r,ans,mid,a[N],b[N],c[N];

bool check(int x){
	f(i,0,n) b[i]=c[i];
	b[0]-=x;
	b[1]+=x;
	f(i,1,n){
		if(b[i]<a[i]) return 1;
		int s=min(b[i]-a[i],c[i]);
		b[(i+1)%n]+=s;
	}
	if(b[0]>=a[0]) ans=1;
	return 0;
}
void solve(){
	l=-1,r=c[0]+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
}

main(){
	cin>>t;
	f(q,0,t){
		ans=0;
		cin>>n;
		f(i,0,n) gett(a[i]);
		f(i,0,n) gett(c[i]);
		solve();
		cout<<(ans ? "YES" : "NO" )<<endl;
	}
}