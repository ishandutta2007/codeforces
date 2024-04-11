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

int n,m,l=-1,r,t,mid,a[N],b[N];

void copy(){
	f(i,1,n+1) a[i]=b[i];
}
bool check(int x){
	copy();
	f(i,1,n+1){
		if(a[i]>a[i-1]){
			if(a[i-1]-a[i]+m<=x)
				a[i]=a[i-1];
		}
		else	if(a[i]<a[i-1]){
			if(a[i-1]-a[i]<=x)
				a[i]=a[i-1];
			else return 0;
		}
	}
	return 1;
}
int main(){
	cin>>n>>m;
	f(i,1,n+1) cin>>b[i];
	r=m;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<endl;
}