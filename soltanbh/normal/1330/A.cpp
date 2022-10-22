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
const int N=21000;
int n,t,a[N],x,mark[N];
int main(){
	cin>>t;
	while(t--){
		f(i,0,1000) mark[i]=0;
		cin>>n>>x;
		f(i,0,n) cin>>a[i];
		f(i,0,n){
			if(!mark[a[i]]) mark[a[i]]=1;
		}
		f(i,1,1000) mark[i]+=mark[i-1];
		f(i,1,1000){
			if(i-mark[i]==x && mark[i+1]==mark[i]){cout<<i<<endl;break;}
		}
	}
}