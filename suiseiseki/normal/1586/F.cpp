#include <cstdio>
const int Maxn=1000;
int col[Maxn+5];
int f[Maxn+5][15];
int main(){
	int k,n;
	scanf("%d%d",&n,&k);
	int max_len=0;
	for(int i=1;i<=n;i++){
		int val=i-1;
		int cur_len=0;
		while(val){
			f[i][cur_len++]=val%k;
			val/=k;
		}
		max_len=cur_len;
	}
	printf("%d\n",max_len);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int t=max_len-1;t>=0;t--){
				if(f[i][t]!=f[j][t]){
					printf("%d ",t+1);
					break;
				}
			}
		}
	}
	puts("");
	return 0;
}