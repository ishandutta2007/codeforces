#include <iostream>
using namespace std;
typedef long long LL;
int t,a,b,c,d;
int main(){
	scanf("%d",&t);
	while(t--){
		int x,y,x1,y1,x2,y2;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
		bool flag=true;
		if(x1==x2 && !(a==0 && b==0)) flag=0;
		if(y1==y2 && !(c==0 && d==0)) flag=0;
		int d1=b-a; x+=d1;
		int d2=d-c; y+=d2;
		if( (x>=x1&&x<=x2) && (y>=y1&&y<=y2) && flag ) printf("Yes\n");
		else printf("No\n");
	}
}