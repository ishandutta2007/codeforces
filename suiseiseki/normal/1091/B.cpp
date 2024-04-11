#include <cstdio>
#define Maxn 2000
struct Point{
	int x,y;
}a[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	int max_x=(-1<<30),max_y=(-1<<30),min_x=(1<<30),min_y=(1<<30);
	for(int i=1;i<=(n<<1);i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		max_x=mx(max_x,a[i].x);
		min_x=mn(min_x,a[i].x);
		max_y=mx(max_y,a[i].y);
		min_y=mn(min_y,a[i].y);
	}
	printf("%d %d\n",max_x+min_x,max_y+min_y);
	return 0;
}