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

int a[333][333],f[606][303][303],n;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)scanf("%d",&a[i][j]);
	memset(f,128,sizeof(f));
	f[0][0][0]=a[0][0];
	for (int i=0;i<n+n-2;i++)for (int j=0;j<=i&&j<n;j++)for (int k=0;k<=i&&k<n;k++){
		int x=j;
		int y=i-j;
		int xx=k;
		int yy=i-k;
		if (x<n-1&&xx<n-1){
			if (x!=xx||y!=yy)f[i+1][j+1][k+1]=max(f[i+1][j+1][k+1],f[i][j][k]+a[x+1][y]+a[xx+1][yy]);else
			f[i+1][j+1][k+1]=max(f[i+1][j+1][k+1],f[i][j][k]+a[x+1][y]);
		}
		if (x<n-1&&yy<n-1){
			if (x+1!=xx||y!=yy+1)f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+a[x+1][y]+a[xx][yy+1]);else
			f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+a[x+1][y]);
		}
		if (y<n-1&&xx<n-1){
			if (x!=xx+1||y+1!=yy)f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a[x][y+1]+a[xx+1][yy]);else
               		f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a[x][y+1]);
		}
		if (y<n-1&&yy<n-1){
			if (x!=xx||y!=yy)f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[x][y+1]+a[xx][yy+1]);else
			f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[x][y+1]);
		}
	}
	CC(f[n+n-2][n-1][n-1]);
	return 0;

}