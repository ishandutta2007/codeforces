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
#define M 100000000

int n1,n2,kk[2],ans=0,f[222][222][22][2];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n1 >> n2 >> kk[0] >> kk[1];
	f[0][0][0][0]=1;
	for (int i=0;i<n1+n2;i++)for (int j=0;j<=n1;j++)for (int l=0;l<2;l++)for (int k=0;k<=kk[l];k++){
		if (l==0){
			f[i+1][j+1][k+1][0]=(f[i+1][j+1][k+1][0]+f[i][j][k][l])%M;
			f[i+1][j][1][1]=(f[i+1][j][1][1]+f[i][j][k][l])%M;
		}else{
			f[i+1][j+1][1][0]=(f[i+1][j+1][1][0]+f[i][j][k][l])%M;
			f[i+1][j][k+1][1]=(f[i+1][j][k+1][1]+f[i][j][k][l])%M;
		}
	}
	for (int i=0;i<2;i++)for (int j=0;j<=kk[i];j++)ans=(ans+f[n1+n2][n1][j][i])%M;
	CC(ans);
	return 0;
}