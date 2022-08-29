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
const int N=105;
int a[N][N];
int n,m;
int f[N][N][26][2];
int dp(int x,int y,int c,int d){
	if(f[x][y][c][d]>=0)return f[x][y][c][d];

	if(d==0){
		rep(i,1,n)if(a[x][i]>=c){
			if(dp(i,y,a[x][i],d^1)==0){
				f[x][y][c][d]=1;
				return 1;
			}
		}
		return f[x][y][c][d]=0;
	}
	else{
		rep(i,1,n)if(a[y][i]>=c){
			if(dp(x,i,a[y][i],d^1)==0){
				f[x][y][c][d]=1;
				return 1;
			}
		}
		return f[x][y][c][d]=0;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	memset(f,-1,sizeof f);
	memset(a,-1,sizeof a);
	while(m--){
		int x,y;scanf("%d%d",&x,&y);
		char s[3];scanf("%s",s);
		a[x][y]=s[0]-'a';
	}
	rep(i,1,n){
		rep(j,1,n){
			if(dp(i,j,0,0)==1){
				putchar('A');
			}
			else putchar('B');
		}
		putchar('\n');
	}
	return 0;
}