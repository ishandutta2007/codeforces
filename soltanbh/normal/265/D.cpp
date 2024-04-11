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

const int N=1e5+99;

int n,ans,a[N],dp[N],mark[N];
vector<int> g[N];

int main(){
	cin>>n;
	f(i,1,n+1){ cin>>a[i]; mark[a[i]]=i; }
	sort(a+1,a+1+n);
	f(i,2,N){
		vector<int> v;
		for(int j=i;j<N;j+=i)
			if(mark[j])
				v.pb(mark[j]);
		f(j,0,max(int(v.size()-1),0))
			g[v[j]].pb(v[j+1]);
	}
	f_(i,n,1){
		f(j,0,g[i].size())
			maxm(dp[i],dp[g[i][j]]+1);
		maxm(ans,dp[i]);
	}
	cout<<ans+1;
}