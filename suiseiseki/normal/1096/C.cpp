#include <cstdio>
int f[400];
int main(){
	for(int i=3;i<=370;i++){
		for(int j=1;j<i-1;j++){
			if((180*j%i)==0){
				if(f[180*j/i]==0){
					f[180*j/i]=i;
				}
			}
		}
	}
	int t;
	int a;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		printf("%d\n",f[a]);
	}
	return 0;
}