#include<stdio.h>
#include<algorithm>
using namespace std;
int r[200100];
int l[200100];
int s[200100];
int n,k,a,b,q;
int getsum(int x,int c[]){
	int ret=0;
	while(x){
		ret+=c[x];
		x-=x&-x;
	}
	return ret;
}
void update(int x,int c[],int v){
	while(x<=n){
		c[x]+=v;
		x+=x&-x;
	}
}
void update(int x,int v){
	int os=s[x];
	s[x]+=v;
	update(x,l,min(s[x],b)-min(os,b));
	update(x,r,min(s[x],a)-min(os,a));
}
int main(){
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);
	for(int i=1;i<=q;++i){
		int x,y,z;
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d",&y,&z);
			update(y,z);
		}
		else{
			scanf("%d",&y);
			printf("%d\n",getsum(y-1,l)+getsum(n,r)-getsum(y+k-1,r));
		}
	}
	return 0;
}