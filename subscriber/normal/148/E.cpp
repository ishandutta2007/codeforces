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
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,m,k[111],a[111][111],f[111],w[111][111],d[111][11111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> k[i];
		for (int j=0;j<k[i];j++)cin >> a[i][j];
		for (int j=0;j<k[i];j++)f[j+1]=f[j]+a[i][j];
		for (int j=0;j<k[i];j++)for (int jj=0;jj<=j;jj++)w[i][k[i]-(j-jj+1)]=max(w[i][k[i]-(j-jj+1)],f[k[i]]-f[j+1]+f[jj]);
		w[i][k[i]]=f[k[i]];
	}
	d[0][0]=0;
	for (int i=0;i<n;i++)for (int j=0;j<=m;j++)for (int jj=0;jj<=k[i];jj++)if (j+jj<=m)d[i+1][j+jj]=max(d[i+1][j+jj],d[i][j]+w[i][jj]);
	CC(d[n][m]);
	return 0;
}