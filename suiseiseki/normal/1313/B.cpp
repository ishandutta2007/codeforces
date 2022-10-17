#include <cstdio>
void swp(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int t;
	int n,x,y;
	scanf("%d",&t);
	int minn,maxn;
	while(t--){
		scanf("%d%d%d",&n,&x,&y);
		if(x>y){
			swp(x,y);
		}
		minn=mn(n-1,mx(0,x+y-n));
		maxn=mn(n,x+y-1);
		printf("%d %d\n",minn+1,maxn);
	}
	return 0;
}