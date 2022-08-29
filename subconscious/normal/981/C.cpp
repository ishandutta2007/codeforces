#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1e5+5;
int b[N],v[N<<1],f[N<<1],tot;
int d[N],n,x,y;
void add(int x,int y){v[++tot]=y,f[tot]=b[x],b[x]=tot;++d[y];}
int dfs(int x,int fa){
	for(int i=b[x];i;i=f[i])
		if(v[i]!=fa)return dfs(v[i],x);
	return x;
}
void sol(int p){
	puts("Yes");
	printf("%d\n",d[p]);
	for(int i=b[p];i;i=f[i])printf("%d %d\n",p,dfs(v[i],p));
}
int main(){
	scanf("%d",&n);
	rep(i,n-1)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	int cnt=0;
	rep(i,n)if(d[i]>2)++cnt;
	if(cnt>=2)puts("No");else{
		rep(i,n)if(d[i]>2){
			sol(i);
	//system("pause");
			return 0;
		}
		sol(1);
	//system("pause");
		return 0;
	}
	//system("pause");
	return 0;
}