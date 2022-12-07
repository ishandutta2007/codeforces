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
int h,m,n,x,u,uu,e,A[111111],B[111111],g;
vector<int>v[111111],s[111111];
char o;
long long ans;

void add(int u,int x,int vv){
	x++;
	while (x<=v[u].size()){
		s[u][x]+=vv;
		x=x+x-(x&(x-1));
	}
}

int find(int u,int x){
	x++;
	int r=0;
	while (x){
		r+=s[u][x];
		x&=x-1;
	}
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> h >> m >> n;
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
	for (int i=1;i<=e;i++)s[i].resize(v[i].size()+5);
	for (int i=0;i<n;i++){
		cin >> o;
		if (o=='-'){
			cin >> x;
			add(w[x],ww[x],-1);
		}else{
			cin >> x >> g;
			u=A[g];
			uu=B[g];
			if (find(u,v[u].size()-1)-find(u,B[g]-1)==v[u].size()-B[g])ans+=v[u].size()-B[g],uu=0;
			for (int j=18;j>=0;j--)if (uu+pw(j)<=v[u].size()&&find(u,uu+pw(j)-1)-find(u,uu-1)==pw(j))ans+=pw(j),uu+=pw(j);
			add(u,uu,1);
			w[x]=u;
			ww[x]=uu;
		}
	}
	CC(ans);
	return 0;
}