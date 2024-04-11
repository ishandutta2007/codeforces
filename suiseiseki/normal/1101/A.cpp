#include <cstdio>
int main(){
	int q;
	int l,r,d;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&l,&r,&d);
		if(d<l){
			printf("%d\n",d);
		}
		else{
			printf("%d\n",(r+d)/d*d);
		}
	}
	return 0;
}