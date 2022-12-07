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

int n,k,x,y,f[50011][505];
vector<int>v[111111];
long long ans=0;

void rec(int x){
	f[x][0]=1;
	int t=-1,o;
	for (int i=0;i<v[x].size();i++)if (!f[v[x][i]][0]){
		rec(v[x][i]);
		for (int j=0;j<=k;j++)f[x][j+1]+=f[v[x][i]][j];
	}else t=i;
	for (int i=0;i<v[x].size();i++)if (i!=t)
	for (int j=0;j<k;j++){
		o=f[x][k-j-1];
		if (k-j-1>0)o-=f[v[x][i]][k-j-2];
		if (j+1<k)ans+=f[v[x][i]][j]*1ll*o;else
		ans+=f[v[x][i]][j]*1ll*o*2;
//		if (f[v[x][i]][j]*1ll*o)cout << x << " " << v[x][i] << " " << j << " " << f[v[x][i]][j]*1ll*o << endl;
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	for (int i=1;i<n;i++){
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	rec(1);
	CC(ans/2);
	return 0;
}