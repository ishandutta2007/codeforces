#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j),__tmp=k;i<=__tmp;i++)
#define per(i,j,k) for(int i=(j),__tmp=k;i>=__tmp;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;bool flag=0;int res=0;
int n,k;int a[15];int fac[15];bool use[15];
int fk(int x){
	//printf("__%d\n",x);
	for(int i=1;i<=13;i++)
	if(!use[i]){
		if(!x){use[i]=1;return i;}
		x--;
	}
}		
void work(int w){
	fac[0]=1;k--;
	for(int i=1;i<=12;i++)fac[i]=fac[i-1]*i;
	if(fac[w]<=k&&!flag){
		printf("-1");
		exit(0);
	}
	for(int i=1;i<=w;i++){
		a[i]=fk(k/fac[w-i]);
		k%=fac[w-i];
		//printf("%d\n",a[i]);
	}
}
bool lucky(int x){
	//printf("%d\n",x);
	while(x){
		if(x%10!=4&&x%10!=7)return 0;
		x/=10;
	}
	return 1;
}
void dfs(int x){
	if(x<=n-13)res++;
	else res+=lucky(a[x-(n-13)]+n-13);
	if(x*10ll+7<=n)dfs(x*10+7);
	if(x*10ll+4<=n)dfs(x*10+4);
}
int main(){
	scanf("%d%d",&n,&k);
	if(n<=13){
		work(n);
		printf("%d\n",(a[4]==4)+(a[7]==7)+(a[4]==7)+(a[7]==4));
	}
	else
	{
		flag=1;
		work(13);
		dfs(4);dfs(7);
		printf("%d\n",res);
	}
	return 0;
}