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

int n,m,t[5555];
double x[5555];
int f[5555][5555];


int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<n;i++)cin >> t[i] >> x[i];
	memset(f,63,sizeof(f));
	f[0][1]=0;
	for (int i=0;i<n;i++)for (int j=1;j<=m;j++){
		if (t[i]==j)f[i+1][j]=min(f[i+1][j],f[i][j]);
		if (j<m)f[i][j+1]=min(f[i][j+1],f[i][j]);
		f[i+1][j]=min(f[i+1][j],f[i][j]+1);
	}
	for (int i=1;i<m;i++)f[n][i+1]=min(f[n][i+1],f[n][i]);
	cout << f[n][m] << endl;
	return 0;
}