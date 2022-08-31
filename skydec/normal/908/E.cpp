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
const int N=1005;
const int P=1000000007;
char a[55][N];
int n,m;
LL b[N];
int f[N][N];
int d[N];
int main(){
	scanf("%d%d",&m,&n);
	rep(i,1,n)scanf("%s",a[i]+1);
	rep(i,1,m){
		rep(j,1,n)b[i]=b[i]*2ll+(a[j][i]-'0');
	}
	sort(b+1,b+1+m);
	int ans=1;
	f[0][0]=1;
	rep(i,0,m)rep(j,0,m){
		f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%P;
		f[i+1][j]=(f[i+1][j]+f[i][j]*1ll*j)%P;
	}
	rep(i,0,m)rep(j,0,m)d[i]=(d[i]+f[i][j])%P;
	rep(i,1,m){
		int j=i;
		while(j<m&&b[j+1]==b[i])++j;
		ans=ans*1ll*d[j-i+1]%P;
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}