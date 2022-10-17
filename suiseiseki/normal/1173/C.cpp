#include <cstdio>
#include <cstring>
#define Maxn 200000
int a[Maxn+5],b[Maxn+5];
int dis[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	if(b[n]==1){
		for(int i=1;i<=n;i++){
			if(b[i]!=0){
				dis[b[i]]=i;
			}
		}
		for(int i=2;i<=n;i++){
			if(dis[i]>i-2){
				printf("%d\n",n*2);
				return 0;
			}
		}
		printf("%d\n",n-1);
		return 0;
	}
	if(b[n]!=0){
		bool yes=1;
		int x=n-1;
		while(1){
			if(b[x]!=b[x+1]-1){
				yes=0;
				break;
			}
			if(b[x]==1){
				break;
			}
			x--;
		}
		if(yes){
			x=n-x+1;
			for(int i=1;i<=n;i++){
				if(b[i]!=0){
					dis[b[i]]=i;
				}
			}
			for(int i=x+1;i<=n;i++){
				if(dis[i]>i-x-1){
					yes=0;
					break;
				}
			}
			if(yes){
				printf("%d\n",n-x);
				return 0;
			}
		}
	}
	bool yes=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			yes=1;
			break;
		}
	}
	if(yes){
		int ans=0;
		memset(dis,0,sizeof dis);
		for(int i=1;i<=n;i++){
			if(b[i]!=0){
				dis[b[i]]=i;
			}
		}
		for(int i=2;i<=n;i++){
			ans=mx(ans,dis[i]-(i-1));
		}
		printf("%d\n",ans+n);
		return 0;
	}
	int x;
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			x=i;
		}
	}
	memset(dis,0,sizeof dis);
	for(int i=x+1;i<=n;i++){
		if(b[i]!=0){
			dis[b[i]]=i-x;
		}
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		ans=mx(ans,dis[i]-(i-1));
	}
	printf("%d\n",ans+x+n);
	return 0;
}