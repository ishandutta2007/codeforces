#include <cstdio>
int main(){
	int w,h;
	scanf("%d%d",&w,&h);
	int u1,d1,u2,d2;
	scanf("%d%d%d%d",&u1,&d1,&u2,&d2);
	for(int i=h;i>0;i--){
		w+=i;
		if(i==d1){
			w-=u1;
			if(w<0){
				w=0;
			}
		}
		if(i==d2){
			w-=u2;
			if(w<0){
				w=0;
			}
		}
	}
	printf("%d\n",w);
	return 0;
}