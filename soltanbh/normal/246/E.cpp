#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+9;
ll n,x,a[N],ans[N],m,v,k,dist[N],cnt,w[N],o,b1,b2,badi[N],l,r,mid,p,tvn=262144,ct,l1=19,sum;
string s,b[N];
vector<ll> g[N],dis[N];
vector<pair<ll,ll> > u;
vector<vector<pair<ll,ll> > > q[N];
map<ll,ll> tedad[N];
map<string,ll> mk[N];
string binary(int m,int k){
	string g="";
	f(i,0,k){
		g+=char((m%2)+'0');
		m=m/2;
	}
	return g;}
void dfs(int x,int ds){
	badi[x]=N*2;
	a[x]=cnt++,dist[x]=ds;
	if(dis[ds].size()>0) badi[dis[ds][dis[ds].size()-1]]=a[x];
	dis[ds].pb(x);
	f(i,0,g[x].size()){
		dfs(g[x][i],ds+1);}
}
ll binary_search(ll x,ll d){
	l=-1,r=dis[d].size();
	while(l+1<r){
		mid=(l+r)/2;
		if(a[dis[d][mid]]<x) l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	get(n);
	f(i,1,n+1){
		cin>>b[i];get(w[i]);
		g[w[i]].pb(i);
	}
	f(i,1,n+1){
		if(w[i]==0) dfs(i,0);
	}	
	f(i,0,n+1){
		while(q[i].size()<dis[i].size()) q[i].pb(u);
	}
	get(m);
	f(i,1,m+1){
		Get(v,k);
		o=dist[v]+k;
		if(o<=n+1){
		b1=binary_search(a[v],o)+1;
		b2=binary_search(badi[v],o);
		ans[i]=b2-b1+1;

		if(b2>=b1)
			q[o][b2].pb(make_pair(b1,i));
		}
	}
	f(i,0,N){
		f(j,0,dis[i].size()){
			if(mk[i][b[dis[i][j]]]!=0){
				p=0,ct=tvn;
				s=binary(mk[i][b[dis[i][j]]],l1);
				f_(e,l1-1,0){
					if(s[e]=='1'){
						p+=ct;
						tedad[i][p]++;
					}
					ct/=2;
				}
			}
			mk[i][b[dis[i][j]]]=j+1;
			f(z,0,q[i][j].size()){
				sum=0;
				s=binary(tvn*2-(q[i][j][z].F+1),l1);
				p=tvn*2,ct=tvn;
				f_(e,l1-1,0){
					if(s[e]=='1'){
						p-=ct;
						sum+=tedad[i][p];
					}
					ct/=2;
				}
				ans[q[i][j][z].S]-=sum;
			}
		}
	}
	f(i,1,m+1) cout<<ans[i]<<" ";
}