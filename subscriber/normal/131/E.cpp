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
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

int n,m,x,y,xx,yy,ans[111111],g[11];
vector<pair<int,int> >v[1111111];


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<m;i++){
		cin >> x >> y;
		v[x].pb(mp(y,i));
		v[n+y].pb(mp(x,i));
		xx=x+y;
		yy=x-y+n;
		v[n+n+xx].pb(mp(yy,i));
		v[4*n+yy].pb(mp(xx,i));
	}
	for (int i=0;i<=6*n;i++)if (v[i].size()>1){
		sort(v[i].begin(),v[i].end());
		ans[v[i][0].S]++;
		ans[v[i][v[i].size()-1].S]++;
		for (int j=1;j<v[i].size()-1;j++)ans[v[i][j].S]+=2;
	}
	for (int i=0;i<m;i++)g[ans[i]]++;
	for (int i=0;i<9;i++)cout << g[i] << " ";
	return 0;
}