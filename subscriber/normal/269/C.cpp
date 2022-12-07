#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#include<cstring>
#include<sstream>
#include<queue>
#define mp make_pair
#define pb push_back
#define pw(x) (1ull<<(x))
#define CC(x) cout << (x) << endl
#define S stringstream
#define m0(x) memset(x,0,sizeof(f))


using namespace std;

int n,m,g[666666],h[666666],e[666666],x[666666],y[666666],k,z;
vector<int>v[666666],w[666666];

void fix(int x){
	e[x]=k++;
	for (int i=0;i<v[x].size();i++){
		g[v[x][i]]+=w[x][i];
		if (v[x][i]>0&&v[x][i]<n-1&&g[v[x][i]]*2==h[v[x][i]])fix(v[x][i]);
	}
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&x[i],&y[i],&z);
		x[i]--;
		y[i]--;
		v[x[i]].pb(y[i]);
		w[x[i]].pb(z);
		v[y[i]].pb(x[i]);
		w[y[i]].pb(z);
		h[x[i]]+=z;
		h[y[i]]+=z;
	}
	fix(0);
	e[n-1]=k;
	for (int i=0;i<m;i++)if (e[x[i]]<e[y[i]])puts("0");else puts("1");
	return 0;
}