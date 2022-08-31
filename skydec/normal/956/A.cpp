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
int a[N][N];
char s[N][N];
int n,m;
bool v1[N],v2[N];
void dd2(int x);
void dd1(int x){
	if(v1[x])return;
	v1[x]=1;
	rep(i,1,m)if(a[x][i])dd2(i);
}
void dd2(int x){
	if(v2[x])return;
	v2[x]=1;
	rep(i,1,n)if(a[i][x])dd1(i);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m)a[i][j]=(s[i][j]=='#');
	while(1){
		int cnt=0;
		rep(i,1,n)rep(j,1,m)cnt+=a[i][j];
		if(!cnt)break;
		memset(v1,0,sizeof v1);
		memset(v2,0,sizeof v2);
		rep(i,1,n)rep(j,1,m)if(a[i][j]){
			dd1(i);
			dd2(j);
			goto l1;
		}
		l1:;
		rep(i,1,n)rep(j,1,m)if(v1[i]&&v2[j]){
			//printf("_%d %d\n",i,j);
			if(!a[i][j]){
				puts("No");
				return 0;
			}
			a[i][j]=0;
		}
	}
	puts("Yes");
	return 0;
}