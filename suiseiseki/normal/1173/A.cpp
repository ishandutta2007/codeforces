#include <cstdio>
int main(){
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	if(z==0){
		if(x==y){
			puts("0");
		}
		else if(x>y){
			puts("+");
		}
		else{
			puts("-");
		}
	}
	else{
		if(x>y+z){
			puts("+");
		}
		else if(x+z<y){
			puts("-");
		}
		else{
			puts("?");
		}
	}
	return 0;
}