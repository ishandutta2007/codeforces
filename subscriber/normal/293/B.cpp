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
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,k,m,a[1111][1111],ans=0,g[1111][1111][11],X[1000111],Y[1000111],qq,u[11];

int rec(int q){
	int x=X[q],y=Y[q];
	if (q==qq)return 1;
	long long r=0;
	int t=-1;
	for (int i=1;i<=k;i++)if ((a[x][y]==0||a[x][y]==i)&&g[x][y][i]==0){
		for (int ii=0;ii<=x;ii++)for (int jj=0;jj<=y;jj++)g[ii][jj][i]++;
		for (int ii=x;ii<n;ii++)for (int jj=y;jj<m;jj++)g[ii][jj][i]++;
		if (a[x][y]==0)u[i]++;
		if (u[i]==1){
			if (t==-1)t=rec(q+1);
			r+=t;
		}else r+=rec(q+1);
		if (a[x][y]==0)u[i]--;
		for (int ii=0;ii<=x;ii++)for (int jj=0;jj<=y;jj++)g[ii][jj][i]--;
		for (int ii=x;ii<n;ii++)for (int jj=y;jj<m;jj++)g[ii][jj][i]--;
	}
	return r%M;
}
                                                                    
int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> k;
	if (n+m-1>k){
		puts("0");
		return 0;
	}
	if (n*m==1){
		if (a[0][0]!=0)cout << 1 << endl;else cout << k << endl;
		return 0;
	}
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)cin >> a[i][j];
	qq=0;
	for (int i=0;i<m;i++)X[qq]=0,Y[qq++]=i;
	for (int j=m-1;j>=0;j--)for (int i=1;i<n;i++)X[qq]=i,Y[qq++]=j;
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)u[a[i][j]]++;
	long long ans=rec(0);
	cout << ans << endl;
	return 0;
}