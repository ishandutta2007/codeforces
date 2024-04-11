#include <cstdio>
const int Maxn=1000000;
int n;
int a[Maxn+5],b[Maxn+5],c[Maxn+5],d[Maxn+5];
bool vis[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%1d",&a[i]);
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%1d",&b[i]);
		}
		for(int i=n,now=1,tmp=1;i>0;i--){
			c[i]=now;
			d[i]=tmp;
			tmp^=1;
			vis[now]=1;
			now=n-now+1;
			if(vis[now]){
				now++;
			}
		}
		int num=0;
		for(int i=n;i>0;i--){
			if((a[c[i]]^d[i])!=b[i]){
				num+=2;
			}
			else{
				num++;
			}
		}
		printf("%d ",num);
		for(int i=n;i>0;i--){
			if((a[c[i]]^d[i])!=b[i]){
				printf("1 %d ",i);
			}
			else{
				printf("%d ",i);
			}
		}
		puts("");
	}
	return 0;
}