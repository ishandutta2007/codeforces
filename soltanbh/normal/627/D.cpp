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
 
const int N=2e5+99;

int n,k,u,v,t=1,ans,mark[N],dp1[N],dp2[N],dppar1[N],dppar2[N],sub[N];
vector<int> g[N];
pair<int,int> a[N];

void dfs(int x,int par){
	sub[x]=1;
	dp1[x]=1,dp2[x]=0;
	bool c=0;
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x),sub[x]+=sub[g[x][i]];
	if(mark[x]!=t){ dp1[x]=0; return ; }
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			if(dp1[g[x][i]]>0) dp1[x]+=dp1[g[x][i]];
			else c=1,maxm(dp2[x],dp2[g[x][i]]);
		}
	if(c) dp2[x]+=dp1[x],dp1[x]=0;
	else dp2[x]=0;
}
void dfsp(int x,int par){
	vector<int> v;
	v.pb(0),v.pb(0),v.pb(dppar2[x]);
	int sum=dppar1[x]+1;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			sum+=dp1[g[x][i]];
			v[0]=dp2[g[x][i]];
			sort(v.begin(),v.end());
		}
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dppar1[g[x][i]]=dppar2[g[x][i]]=0;
			if(mark[x]==t && mark[g[x][i]]==t){
				if(sum-dp1[g[x][i]]==n-sub[g[x][i]]) dppar1[g[x][i]]=sum-dp1[x];
				else{
					dppar2[g[x][i]]=sum-dp1[g[x][i]];
					if(v[2]==dp2[g[x][i]]) dppar2[g[x][i]]+=v[1];
					else dppar2[g[x][i]]+=v[2];
				}
			}
			dfsp(g[x][i],x);
		}
	if(mark[x]==t) maxm(ans,sum+v[2]);
}
bool check(int an){
	ans=0;
	f(i,1,an+1)
		mark[a[i].S]=t;
	dfs(1,0);
	dfsp(1,0);
	t++;
	return ans>=k;
}
void solve(){
	int l=0,r=n,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<a[r].F;
}
int main(){
	cin>>n>>k;
	f(i,1,n+1){ cin>>a[i].F; a[i].S=i; }
	f(i,1,n){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	solve();
}