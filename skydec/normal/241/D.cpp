//orz YJN
//
//
//
//IGM
//
//
//
//
//
//Orz Orz Orz Orz Orz
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
bool f[33][33][50005];bool all[33][33][50005];
int n,p;int t;int b[35];bool flag;int gt[33];int num[33];
inline int add(int x,int y){
	if(y>=10)x*=100;else x*=10;
	x+=y;
	return x%p;
}
int main(){
	scanf("%d%d",&n,&p);
	f[0][0][0]=1;
	rep(i,1,n){
		int x;scanf("%d",&x);
		if(x>=32)continue;
		b[++t]=x;num[t]=i;
		rep(j,0,31)rep(k,0,p-1)if(f[t-1][j][k]){
			f[t][j][k]=1;all[t][j][k]=0;
			int y=add(k,x);
			f[t][j^x][y]=1;all[t][j^x][y]=1;
			if(j==x&&!y){flag=1;goto yes;}
		}
	}
	yes:;
	if(flag){
		printf("Yes\n");
		int top=0;
		int u=0;int v=0;
		per(i,t,1){
			if(all[i][u][v]){
				gt[++top]=num[i];
				u^=b[i];
				rep(j,0,p-1)if(f[i-1][u][j]&&add(j,b[i])==v){
					v=j;
					break;
				}
			}
		}
		printf("%d\n",top);
		per(i,top,1)printf("%d ",gt[i]);
	}
	else printf("No\n");
	return 0;
}