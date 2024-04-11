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

const int N=2005;

int n,b,g,j,ans=N,a[N];

int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		b+=(a[i]==1);
	}
	if(b) return cout<<n-b,0;
	f(i,0,n){
		g=a[i];
		for(j=i+1;j<n && g!=1;j++)
			g=__gcd(g,a[j]);
		if(g==1){ minm(ans,j-i);}
	}
	if(ans==N) return cout<<-1,0;
	cout<<n-2+ans;
}