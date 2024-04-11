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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const ll N=5e5+9,e=1e9;

ll n,t,a[N],mark[N],s;

ll md(ll x){
	if(x<0) x+=e*n;
	return x%n;
}
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n;
		int ans=1;
		fill(mark,mark+n,0);
		f(i,0,n) cin>>a[i];
		f(i,0,n){
			if(mark[md(i+a[i])]==0)
				mark[md(i+a[i])]=1;
			else
				ans=0;
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}