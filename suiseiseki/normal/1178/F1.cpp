#include <cstdio>
#include <cstring>
#define Maxn 500
#define Mod 998244353
int a[Maxn+5];
int f[Maxn+5][Maxn+5];
int n,m;
int dfs(int left,int right){
	if(f[left][right]!=-1){
		return f[left][right];
	}
	if(right+1==left){
		return f[left][right]=1;
	}
	int p=left;
	for(int i=left;i<=right;i++){
		if(a[i]<a[p]){
			p=i;
		}
	}
	int sum_1=0,sum_2=0;
	for(int i=left;i<=p;i++){
		sum_1+=1ll*dfs(left,i-1)*dfs(i,p-1)%Mod;
		sum_1%=Mod;
	}
	for(int i=p;i<=right;i++){
		sum_2+=1ll*dfs(i+1,right)*dfs(p+1,i)%Mod;
		sum_2%=Mod;
	}
	return f[left][right]=1ll*sum_1*sum_2%Mod;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	memset(f,-1,sizeof f);
	printf("%d\n",dfs(1,n));
	return 0;
}