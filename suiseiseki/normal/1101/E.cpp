#include <cstdio>
#define Maxn 500000
char qu[5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	int x,y;
	int h=0,w=0;
	while(n--){
		scanf("%s",qu);
		scanf("%d%d",&x,&y);
		if(x<y){
			x^=y^=x^=y;
		}
		if((*qu)=='+'){
			h=mx(h,x);
			w=mx(w,y);
		}
		else{
			if(x>=h&&y>=w){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
	}
	return 0;
}