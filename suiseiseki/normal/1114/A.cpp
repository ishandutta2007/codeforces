#include <cstdio>
int main(){
	int x,y,z;
	int a,b,c;
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&a,&b,&c);
	if(x>a){
		puts("NO");
		return 0;
	}
	a-=x;
	a+=b;
	if(y>a){
		puts("NO");
		return 0;
	}
	a-=y;
	a+=c;
	if(z>a){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}