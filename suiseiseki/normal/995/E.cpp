#include <ctime>
#include <random>
#include <cstdio>
using namespace std;
const int Maxl=200;
int get_len(int a,int b){
	if(b==0){
		return 0;
	}
	return get_len(b,a%b)+a/b+1;
}
mt19937 rnd(time(0));
int get_path(int u,int p,bool *c){
	int a,b,l=0;
	do{
		b=rnd()%(p-1)+1;
		a=1ll*u*b%p;
	}while(get_len(a,b)>100);
	while(b!=0){
		if(a<b){
			c[++l]=0;
			swap(a,b);
		}
		else{
			a-=b;
			c[++l]=1;
		}
	}
	return l;
}
bool c1[Maxl+5],c2[Maxl+5];
int main(){
	int u,v,p;
	scanf("%d%d%d",&u,&v,&p);
	int l1=get_path(u,p,c1);
	int l2=get_path(v,p,c2);
	printf("%d\n",l1+l2);
	for(int i=1;i<=l1;i++){
		printf("%d ",c1[i]?2:3);
	}
	for(int i=l2;i>0;i--){
		printf("%d ",c2[i]?1:3);
	}
	puts("");
	return 0;
}