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
const int N=3e5+9;
int n,m,x,y,c,a[N],b[N],par[N],cmpsz[N],mxcmp[N];
void merge(int x,int y){
	c=mxcmp[par[y]];
	if(cmpsz[par[x]]<cmpsz[par[y]]){
		for(int i=x-1;i>=0 && par[i]==par[x];i--)
			par[i]=par[y];
		par[x]=par[y];
		cmpsz[par[y]]+=cmpsz[par[x]];
	}
	else{
		for(int i=x+1;i<=y;i++)
			par[i]=par[x];
		cmpsz[par[x]]+=cmpsz[par[y]];
		mxcmp[par[x]]=c;
	}
}
void add(int x,int y){
	x=mxcmp[par[x]];
	if(a[x]<=y){
		y-=a[x];
		a[x]=0;
		if(x==n-1){ return ;}
		merge(x,x+1);
		add(x,y);
		return ;
	}
	a[x]-=y;
}
int main(){
	cin>>n;
	f(i,0,n) mxcmp[i]=par[i]=i,cmpsz[i]=1;
	f(i,0,n){ gett(a[i]);b[i]=a[i];}
	cin>>m;
	f(i,0,m){
		gett(x);
		if(x==1){
			Gett(x,y);
			x--;
			add(x,y);
		}
		else{
			gett(x);
			x--;
			cout<<b[x]-a[x]<<endl;
		}
	}
}