#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	if(n==1||n==2){
		puts("1");
		return 0;
	}
	int x=4,y=5;
	int nx,ny;
	while(y<n){
		if(x&1){
			nx=x+y+1;
			ny=y+y+1;
		}
		else{
			nx=x+y+1;
			ny=x+x+1;
		}
		if(nx>ny){
			nx^=ny^=nx^=ny;
		}
		x=nx;
		y=ny;
	}
	if(x==n||y==n){
		puts("1");
	}
	else{
		puts("0");
	}
	return 0;
}