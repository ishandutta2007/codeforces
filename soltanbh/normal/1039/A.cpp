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

const int N=5e5+99;
const ll inf=2e18;

ll n,t,a[N],x[N],mark[N];

int main(){
	cin>>n>>t;
	f(i,1,n+1) get(a[i]);
	f(i,1,n+1){
		get(x[i]);
		if(x[i]<i || (x[i]!=x[i-1] && x[i-1]!=i-1)) return cout<<"No",0;
		mark[x[i]+1]=1;
	}
	f(i,1,n+1) mark[i]=1-mark[i];
	f(i,2,n)
		if(mark[i] && !mark[i+1] && a[i]+1==a[i+1]) return cout<<"No",0;
	cout<<"Yes"<<endl;
	f(i,1,n){
		if(mark[i+1])
			cout<<a[i+1]+t<<" ";
		else
			cout<<a[i+1]+t-1<<" ";
	}
	cout<<inf+2ll;
}