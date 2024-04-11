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
const int N=2005;
int a[N],n;
int f[N][N][2][2];
int s[N][2];
int g[N][2];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		--a[i];
	}
	rep(i,1,n)f[i][i][a[i]][a[i]]=1;
	rep(len,2,n){
		rep(l,1,n-len+1){
			int r=l+len-1;
			rep(v1,0,1)rep(v2,0,v1){
				f[l][r][v1][v2]=max(max(f[l+1][r][v1][v2],f[l][r][v1][v2]),f[l][r-1][v1][v2]);
				if(a[l]>=v1)f[l][r][a[l]][v2]=max(f[l][r][a[l]][v2],f[l+1][r][v1][v2]+1);
				if(v2>=a[r])f[l][r][v1][a[r]]=max(f[l][r][v1][a[r]],f[l][r-1][v1][v2]+1);
			}
		}
	}
	rep(i,1,n)rep(j,0,1){
		g[i][j]=max(g[i][j],g[i-1][j]);
		if(j<=a[i])g[i][a[i]]=max(g[i][a[i]],g[i-1][j]+1);
	}
	per(i,n,1)rep(j,0,1){
		s[i][j]=max(s[i][j],s[i+1][j]);
		if(a[i]<=j)s[i][a[i]]=max(s[i][a[i]],s[i+1][j]+1);
	}
	rep(i,1,n){
		g[i][1]=max(g[i][1],g[i][0]);
		s[i][0]=max(s[i][0],s[i][1]);
	}
	int ans=0;
	rep(l,1,n)rep(r,l,n)rep(v1,0,1)rep(v2,0,v1)ans=max(ans,f[l][r][v1][v2]+g[l-1][v2]+s[r+1][v1]);
	printf("%d\n",ans);
	return 0;
}