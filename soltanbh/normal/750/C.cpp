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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=5e5+99,mid=1900;

int n,t,a[N],d[N],mn=-1e18,mx=1e18;

main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i]>>d[i];
		if(d[i]==1){
			maxm(mn,mid)
			if(mn>mx) return cout<<"Impossible",0;
			mn+=a[i],mx+=a[i];
		}
		else{
			minm(mx,mid-1);
			if(mn>mx) return cout<<"Impossible",0;
			mn+=a[i];
			mx+=a[i];
		}
	}
	if(mx>1e9) return cout<<"Infinity",0;
	cout<<mx;
}