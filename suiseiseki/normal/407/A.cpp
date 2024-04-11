#include <cmath>
#include <cstdio>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	bool flag=0;
	int ax,ay,bx,by;
	for(ax=1;ax<a;ax++){
		for(bx=1;bx<b;bx++){
			ay=(int)sqrt(a*a-ax*ax);
			by=(int)sqrt(b*b-bx*bx);
			if(ax*ax+ay*ay==a*a&&bx*bx+by*by==b*b){
				if(ax*bx==ay*by){
					if(ax!=bx){
						flag=1;
						break;
					}
				}
			}
		}
		if(flag){
			break;
		}
	}
	if(!flag){
		puts("NO");
	}
	else{
		puts("YES");
		puts("0 0");
		printf("%d %d\n",ax,-ay);
		printf("%d %d\n",bx,by);
	}
	return 0;
}