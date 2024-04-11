#include <cstdio>
const int Maxn=200000;
int n;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n<8){
			int num=0;
			for(int i=3;i<n;i++){
				num++;
			}
			int tmp=n;
			while(tmp>1){
				tmp=(tmp+1)>>1;
				num++;
			}
			printf("%d\n",num);
			for(int i=3;i<n;i++){
				printf("%d %d\n",i,n);
			}
			tmp=n;
			while(tmp>1){
				tmp=(tmp+1)>>1;
				printf("%d %d\n",n,2);
			}
		}
		else{
			int num=0;
			for(int i=3;i<n;i++){
				if(i!=8){
					num++;
				}
			}
			if(n!=8){
				int tmp=n;
				while(tmp>1){
					tmp=(tmp-1)/8+1;
					num++;
				}
			}
			num+=3;
			printf("%d\n",num);
			for(int i=3;i<n;i++){
				if(i!=8){
					printf("%d %d\n",i,n);
				}
			}
			if(n!=8){
				int tmp=n;
				while(tmp>1){
					tmp=(tmp-1)/8+1;
					printf("%d %d\n",n,8);
				}
			}
			printf("8 2\n8 2\n8 2\n");
		}
	}
	return 0;
}