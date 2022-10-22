#include<cstdio>
using namespace std;
int T,x,y;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&x,&y);
		if(x>y) printf("%d\n",x+y);
		else printf("%d\n",(y+y/x*x)/2);
	}
	return 0;
}