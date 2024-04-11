#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=1005;
int n;
int x[N],y[N];
bool col[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
	while(1){
		col[1]=0;
		rep(i,2,n){
			if(((x[i]-x[1])*1ll*(x[i]-x[1])+(y[i]-y[1])*1ll*(y[i]-y[1]))%2==0)
				col[i]=0;
			else col[i]=1;
		}
		bool flg=0;
		rep(i,1,n)if(col[i]==1)flg=1;
		if(flg)break;
		rep(i,1,n){
			if((x[i]+y[i])%2==0){
				int dx=(x[i]+y[i])/2;
				int dy=(x[i]-y[i])/2;
				x[i]=dx;
				y[i]=dy;
			}
			else{
				int dx=(x[i]+y[i]+1)/2;
				int dy=(x[i]-y[i]+1)/2;
				x[i]=dx;
				y[i]=dy;
			}
		}
	}
	int res=0;
	rep(i,1,n)if(!col[i])++res;
	printf("%d\n",res);
	rep(i,1,n)if(!col[i])printf("%d ",i);puts("");
	return 0;
}