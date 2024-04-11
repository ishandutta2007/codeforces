#include <cstdio>
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int t;
	int b,p,f;
	int h,c;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&b,&p,&f);
		scanf("%d%d",&h,&c);
		if(h>=c){
			if(b>=(p<<1)){
				b-=(p<<1);
				printf("%d\n",mn(b>>1,f)*c+p*h);
			}
			else{
				printf("%d\n",(b>>1)*h);
			}
		}
		else{
			if(b>=(f<<1)){
				b-=(f<<1);
				printf("%d\n",mn(b>>1,p)*h+f*c);
			}
			else{
				printf("%d\n",(b>>1)*c);
			}
		}
	}
	return 0;
}