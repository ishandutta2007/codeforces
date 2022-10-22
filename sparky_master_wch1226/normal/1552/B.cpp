#include<bits/stdc++.h>
using namespace std;const int N=5e4+7;
int a[N][7],n,m,i,j,T_T,id[N];
bool cmp(int x,int y){int cnt=0;for(int i=0;i<5;++i)if(a[x][i]<a[y][i])++cnt;return cnt>=3;}
int main(){
	for(scanf("%d",&T_T);T_T--;){
		for(scanf("%d",&n),i=0;i<n;++i)for(j=0,id[i]=i;j<5;++j)scanf("%d",a[i]+j);sort(id,id+n,cmp);
		for(j=0,i=1;i<n;++i)if(!cmp(id[0],id[i]))j=1;printf("%d\n",j?-1:id[0]+1);
	}
}