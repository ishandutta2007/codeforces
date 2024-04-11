#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Maxn 25
#define Maxs 1250000
int a[Maxn<<1|5];
int n;
int mn(int a,int b){
	return a<b?a:b;
}
int ab(int a){
	return a<0?-a:a;
}
int mx(int a,int b){
	return a>b?a:b;
}
int f[Maxn+5][Maxs+5];
bool vis[Maxn<<1|5];
void print(int x,int s){
	if(x==0){
		return;
	}
	print(x-1,s-a[f[x][s]]);
	printf("%d ",a[f[x][s]]);
	vis[f[x][s]]=1;
}
int main(){
	scanf("%d",&n);
	f[0][0]=1;
	int sum=0;
	for(int i=1;i<=(n<<1);i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+(n<<1));
	sum-=(a[1]+a[2]);
	memset(f,-1,sizeof f);
	f[0][0]=0;
	for(int i=3;i<=(n<<1);i++){
		for(int k=n-1;k>0;k--){
			for(int j=mn(Maxs,sum);j>=a[i];j--){
				if(f[k][j]!=-1){
					continue;
				}
				if(f[k-1][j-a[i]]!=-1){
					f[k][j]=i;
				}
			}
		}
	}
	int x=0;
	int ans=(1<<30);
	int now;
	for(int i=0;i<=Maxs;i++){
		if(f[n-1][i]==-1){
			continue;
		}
		now=mx(i+a[1]+a[2],sum-i+a[1]+a[2]);
		if(now<ans){
			ans=now;
			x=i;
		}
	}
	printf("%d ",a[1]);
	vis[1]=1;
	print(n-1,x);
	puts("");
	for(int i=(n<<1);i>0;i--){
		if(!vis[i]){
			printf("%d ",a[i]);
		}
	}
	puts("");
	return 0;
}