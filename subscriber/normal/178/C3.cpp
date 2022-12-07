#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

map<int,int>w,ww;
set<int>S[222222];
int h,m,n,x,u,uu,e,A[311111],B[311111],g,vv[222222],os[222222],oo[222222],fl[222222];
vector<int>v[211111],s[211111];
char o;
long long ans;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d%d\n",&h,&m,&n); 
	for (int i=0;i<h;i++)if (!A[i]){
		x=i;
		A[i]=++e;
		B[i]=0;
		v[e].pb(i);
		x=(x+m)%h;
		while (x!=i){
			B[x]=v[e].size();
			v[e].pb(x);
			A[x]=e;
			x=(x+m)%h;
		}
	}
	for (int i=1;i<=e;i++)for (int j=0;j<v[i].size();j++)S[i].insert(j);
	for (int i=0;i<n;i++){
		scanf("%c",&o);
		if (o=='-'){
			scanf("%d\n",&x);
			S[w[x]].insert(ww[x]);
		}else{
			scanf("%d%d\n",&x,&g);
			u=A[g];
			uu=B[g];
			if (S[u].lower_bound(uu)==S[u].end())ans+=v[u].size()-uu,uu=0;
			int z=*S[u].lower_bound(uu);
			S[u].erase(z);
			ans+=z-uu;
			w[x]=u;
			ww[x]=z;
		}
	}
	CC(ans);
	return 0;
}