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

int n,x,pr[21][111111],de[111111],t[111111],le[111111],ri[111111],tt,m,y;
vector<int>g[111111],v[111111];

void rec(int x,int d){
	t[x]=++tt;
	le[x]=tt;
	de[x]=d;
	for (int i=0;i<v[x].size();i++)rec(v[x][i],d+1);
	ri[x]=tt;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> x;
		pr[0][i]=x;
		v[x].pb(i);
	}
	rec(0,0);
	for (int i=1;i<20;i++)for (int j=0;j<=n;j++)if (!pr[i-1][j])pr[i][j]=0;else pr[i][j]=pr[i-1][pr[i-1][j]];
	for (int i=0;i<=n;i++)g[de[i]].pb(t[i]);          
	for (int i=0;i<=n+2;i++)if (g[i].size())sort(g[i].begin(),g[i].end());
	cin >> m;
	for (int i=0;i<m;i++){
		cin >> x >> y;
		if (de[x]<=y){
			printf("0 ");
			continue;
		}
		int xx=x;
		for (int j=19;j>=0;j--)if (y&pw(j))xx=pr[j][xx];
		int ans=upper_bound(g[de[x]].begin(),g[de[x]].end(),ri[xx])-lower_bound(g[de[x]].begin(),g[de[x]].end(),le[xx]);
		printf("%d ",ans-1);
	}
	return 0;
}