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

int n,m,t;
long long c[33][33],ans=0;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> t;
	c[0][0]=1;
	for (int i=1;i<=30;i++)for (int j=0;j<=i;j++)if (!j)c[i][j]=c[i-1][j];else c[i][j]=c[i-1][j]+c[i-1][j-1];
	for (int i=4;i<t;i++)if (i<=n&&(t-i)<=m)ans+=c[n][i]*c[m][t-i];
	CC(ans);
	return 0;
}