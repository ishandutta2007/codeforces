#include <cstdio>
int main(){
	int t;
	int x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		if(x==1){
			if(y<=1){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
		else if(x<=3){
			if(y<=3){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
		else{
			puts("YES");
		}
	}
	return 0;
}