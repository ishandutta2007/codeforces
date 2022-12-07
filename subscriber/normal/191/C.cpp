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

int de[111111],w[111111],v[111111],s[111111],x,y,kk,yy[222222],an[222222],xx[222222],pp[222222],ans[111111],pr[20][111111],n,m,dd[111111];

int lca(int x,int y){
	for (int i=18;i>=0;i--)if (pr[i][x]!=-1&&de[pr[i][x]]>=de[y])x=pr[i][x];
	for (int i=18;i>=0;i--)if (pr[i][y]!=-1&&de[pr[i][y]]>=de[x])y=pr[i][y];
	if (x==y)return x;
	for (int i=18;i>=0;i--)if (pr[i][x]!=-1&&pr[i][x]!=pr[i][y])x=pr[i][x],y=pr[i][y];
	return pr[0][x];
}

void rec(int x,int p,int d){
	if (dd[x])return;
	dd[x]=1;
	de[x]=d;
	for (int w=xx[x];w;w=pp[w])if (yy[w]!=p){
		pr[0][yy[w]]=x;
		rec(yy[w],x,d+1);
	}
}

void rc(int x,int p){
	if (w[x])return;
	w[x]=1;
	s[x]=v[x];
	for (int w=xx[x];w;w=pp[w])if (yy[w]!=p){
		rc(yy[w],x);
		ans[an[w]]=s[yy[w]];
		s[x]+=s[yy[w]];
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		yy[++kk]=y;
		an[kk]=i-1;
		pp[kk]=xx[x];
		xx[x]=kk;
		yy[++kk]=x;
		an[kk]=i-1;
		pp[kk]=xx[y];
		xx[y]=kk;
	}
	for (int i=0;i<n;i++)for (int j=0;j<19;j++)pr[j][i]=-1;
	rec(0,-1,0);
	for (int i=1;i<19;i++)for (int j=0;j<n;j++)if (pr[i-1][j]==-1)pr[i][j]=-1;else pr[i][j]=pr[i-1][pr[i-1][j]];
	cin >> m;
	for (int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		int h=lca(x,y);
		if (x==h||y==h){
			if (y==h)swap(x,y);
			v[y]++;
			v[x]--;
		}else{
			v[x]++;
			v[y]++;
			v[h]-=2;
		}
	}
	rc(0,-1);
	for (int i=0;i<n-2;i++)printf("%d ",ans[i]);
	CC(ans[n-2]);
	return 0;
}