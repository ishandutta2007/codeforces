#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=205;
int n;
int f[N][N];
int main(){
	scanf("%d",&n);
	f[0][0]=1;
	f[1][1]=1;
	rep(i,2,n){
		rep(j,1,i)f[i][j]=f[i-1][j-1]+f[i-2][j];
		f[i][0]=f[i-2][0];
		bool flg=1;
		rep(j,0,i)if(abs(f[i][j])>1)flg=0;
		if(flg)continue;

		rep(j,1,i)f[i][j]=f[i-1][j-1]-f[i-2][j];
		f[i][0]=-f[i-2][0];

		flg=1;
		rep(j,0,i)if(abs(f[i][j])>1)flg=0;
	}
	printf("%d\n",n);
	rep(i,0,n)printf("%d ",f[n][i]);puts("");
	printf("%d\n",n-1);
	rep(i,0,n-1)printf("%d ",f[n-1][i]);puts("");
	return 0;
}