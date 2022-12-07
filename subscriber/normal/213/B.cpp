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

int nn,a[11];
long long C[222][222],f[12][122],ans=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> nn;
	for (int i=0;i<10;i++)cin >> a[i];
	C[0][0]=1;
	for (int i=1;i<=111;i++)for (int j=0;j<=i;j++)if (!j)C[i][j]=C[i-1][j];else C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	for (int n=0;n<nn;n++)
	for (int x=1;x<10;x++){
		a[x]--;
		m0(f);
		f[0][0]=1;
		for (int i=0;i<10;i++)for (int j=0;j<=n;j++)for (int l=max(0,a[i]);l+j<=n;l++)if (f[i][j])f[i+1][j+l]=(f[i+1][j+l]+f[i][j]*C[n-j][l])%M;
		ans=(ans+f[10][n])%M;
		a[x]++;
	}
	CC(ans);
	return 0;
}