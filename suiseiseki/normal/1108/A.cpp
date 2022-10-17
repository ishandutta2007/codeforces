#include <cstdio>
int main(){
	int n;
	int l_1,r_1,l_2,r_2;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d",&l_1,&r_1,&l_2,&r_2);
		if(l_1!=l_2){
			printf("%d %d\n",l_1,l_2);
		}
		else if(l_1==l_2&&l_1==r_1){
			printf("%d %d\n",l_1,l_2+1);
		}
		else{
			printf("%d %d\n",l_1+1,l_2);
		}
	}
	return 0;
}