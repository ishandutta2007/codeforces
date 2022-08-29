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
const int N=55;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char a[N][N];
int n,m;
int sx,sy,ex,ey;
char s[N*10];
int p[4];
bool check(){
	int dd=strlen(s+1);
	int nx=sx;
	int ny=sy;
	rep(i,1,dd){
		int d=p[s[i]-'0'];
		nx+=dx[d];
		ny+=dy[d];
		if(!(nx<=n&&nx>=1&&ny<=m&&ny>=1))return 0;
		if(a[nx][ny]=='#')return 0;
		if(a[nx][ny]=='E')return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",a[i]+1);
	scanf("%s",s+1);
	rep(i,1,n)rep(j,1,m)if(a[i][j]=='S'){
		sx=i;sy=j;
	}
	else if(a[i][j]=='E'){
		ex=i;ey=j;
	}
	rep(i,0,3)p[i]=i;
	int ans=0;
	rep(Cas,1,24){
		if(check())++ans;
		next_permutation(p,p+4);
	}
	printf("%d\n",ans);
	return 0;
}