#include <cstdio>
#include <cstring>
#define Maxn 300000
#define Inf 0x7f7f7f7f
int a[Maxn+5];
int b[Maxn+5],e[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	memset(b,0x7f,sizeof b);
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		e[i]=-Inf;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=mn(b[a[i]],i);
		e[a[i]]=mx(e[a[i]],i);
	}
	int b_x=0,b_n=0,e_x=0,e_n=0;
	for(int i=1;i<=n;i++){
		if(b[i]==Inf){
			continue;
		}
		if(b[i]<b[b_x]){
			b_n=b_x;
			b_x=i;
		}
		else if(b[i]<b[b_n]){
			b_n=i;
		}
		if(e[i]>e[e_x]){
			e_n=e_x;
			e_x=i;
		}
		else if(e[i]>e[e_n]){
			e_n=i;
		}
	}
	if(b_x!=e_x){
		printf("%d\n",e[e_x]-b[b_x]);
	}
	else{
		printf("%d\n",mx(e[e_n]-b[b_x],e[e_x]-b[b_n]));
	}
	return 0;
}