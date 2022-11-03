#include<cstdio>
using namespace std;

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int x=a+b-c,y=b+c-a,z=c+a-b;
	if(x%2 || y%2 || z%2){
		printf("Impossible\n");
		return 0;
	}
	x/=2,y/=2,z/=2;
	if(x==0 && y==0 || y==0 && z==0 || x==0 && z==0){
		printf("Impossible\n");
		return 0;
	}
	if(x<0 || y<0 || z<0){
		printf("Impossible\n");
		return 0;
	}
	printf("%d %d %d\n",x,y,z);
	return 0;
}