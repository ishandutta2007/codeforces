#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n,h,a,b,k;
	scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
	int ta,fa,tb,fb;
	while(k--){
		scanf("%d%d%d%d",&ta,&fa,&tb,&fb);
		if(ta==tb){
			printf("%d\n",abs(fa-fb));
		}
		else{
			if(a<=fa&&fa<=b){
				printf("%d\n",abs(fa-fb)+abs(ta-tb));
			}
			else{
				if(fa>b){
					printf("%d\n",abs(fa-b)+abs(ta-tb)+abs(b-fb));
				}
				else{
					printf("%d\n",abs(fa-a)+abs(ta-tb)+abs(a-fb));
				}
			}
		}
	}
	return 0;
}