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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+9;
int t,a[N],x,n,m;
int main(){
	cin>>t;
	while(t--){
		cin>>x>>n>>m;
		while(x>0 && n && x/2+10<x){
			n--;
			x/=2;
			x+=10;
		}
		while(x>0 && m) x-=10,m--;
		if(x>0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}