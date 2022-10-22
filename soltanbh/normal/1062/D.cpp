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

const int N=5e5+9;

ll t,n,sum,ans,mark[N];
vector<pair<ll,ll> > g[N];

void dfs(int x){
	mark[x]=1;
	f(i,0,g[x].size()){
		sum+=g[x][i].S;
		if(!mark[g[x][i].F])
			dfs(g[x][i].F);
	}
}

int main(){
	cin>>n;
	f(i,2,n+1)
		for(int j=i*2;j<=n;j+=i)
			g[i].pb(mp(j,j/i)),g[j].pb(mp(i,j/i));
	f(i,2,n+1)
		if(!mark[i]){
			sum=0;
			dfs(i);
			maxm(ans,sum);
		}
	cout<<ans*2;
}