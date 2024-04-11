#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=3e5+20;
 
int n,k,x,c,sum,cmp[N],szcmp[N],ans[N],turn[N],a[N],b[N],yekta[N];
vector<int> g[N],comp[N];
string s;
 
int xrr(int x,int y){
	return (x!=y);
}
 
void dsu(int c1,int c2){
	if(szcmp[c1]<szcmp[c2]) swap(c1,c2);
	yekta[c1]=(yekta[c1] || yekta[c2]);
	ans[c1]+=ans[c2];
	szcmp[c1]+=szcmp[c2];
	f(i,0,comp[c2].size()){
		int u=comp[c2][i];
		cmp[u]=c1,turn[u]=xrr(turn[u],xrr(b[c1],b[c2]));
		comp[c1].pb(u);
	}
}
 
void add_vertex(int x){
	if(!g[x].size()) return ;
	if(g[x].size()==1){
		int c=cmp[g[x][0]];
		yekta[c]=1;
		if(xrr(a[x],xrr(b[c],turn[g[x][0]]))==0){
			sum+=szcmp[c]-ans[c]*2;
			ans[c]=szcmp[c]-ans[c];
			b[c]=!b[c];
		}
		return ;
	}
	int c1=cmp[g[x][0]],c2=cmp[g[x][1]];
	
	if(cmp[c2]==cmp[c1]) return ;
 
	if(xrr(xrr(turn[g[x][0]],b[c1]),xrr(turn[g[x][1]],b[cmp[c2]]))!=a[x]){
		dsu(c1,c2);
		return ;
	}
	
	if(yekta[c2] || (yekta[c1]==0 && szcmp[c2]-ans[c2]*2>szcmp[c1]-ans[c1]*2)){
		sum+=szcmp[c1]-ans[c1]*2;
		b[c1]=!b[c1];
		ans[c1]=szcmp[c1]-ans[c1];
	}
	else{
		sum+=szcmp[c2]-ans[c2]*2;
		b[c2]=!b[c2];
		ans[c2]=szcmp[c2]-ans[c2];
	}
	dsu(c1,c2);
}
 
int main(){
	cin>>n>>k>>s;
	f(i,1,n+1) 
		a[i]=(s[i-1]=='1');
	
	k++;
	f(i,1,k){
		comp[i].pb(i);
		cmp[i]=i,szcmp[i]=1;
		gett(c);
		f(j,0,c){
			gett(x);
			g[x].pb(i);
		}
	
	}
	f(i,1,n+1){
		add_vertex(i);
		cout<<sum<<endl;
	}
}