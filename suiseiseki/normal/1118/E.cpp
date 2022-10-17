#include <cstdio>
#define Maxn 200000
int b[Maxn+5],g[Maxn+5];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if((long long)k*(k-1)<n){
		puts("NO");
		return 0;
	}
	puts("YES");
	int i,j;
	i=1,j=1;
	while(n>0){
		j++;
		if(j>k){
			i++;
			j=i+1;
		}
		printf("%d %d\n",i,j);
		n--;
		if(n>0){
			printf("%d %d\n",j,i);
			n--;
		}
	}
	return 0;
}