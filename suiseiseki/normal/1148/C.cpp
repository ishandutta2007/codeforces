#include <cstdio>
#define Maxn 300000
int a[Maxn+5],b[Maxn+5];
int ans_a[Maxn*5+5],ans_b[Maxn*5+5];
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int tot;
void sp(int x,int y){
	ans_a[++tot]=x;
	ans_b[tot]=y;
	swap(a[x],a[y]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int x;
	bool change=0;
	for(int i=2;i<n;i++){
		if(a[i]==i){
			continue;
		}
		x=a[i];
		if(i<=n/2){
			sp(i,n);
			if(!change&&i==n){
				puts("Opps!");
			}
			change=1;
			if(x==n){
				i--;
				continue;
			}
			if(x<=n/2){
				sp(n,x);
			}
			else{
				sp(n,1);
				sp(1,x);
			}
		}
		else{
			sp(i,1);
			if(x==1){
				i--;
				continue;
			}
			if(x>=n/2){
				sp(1,x);
			}
			else{
				sp(1,n);
				sp(n,x);
			}
		}
		i--;
	}
	if(a[1]==n){
		sp(1,n);
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		printf("%d %d\n",ans_a[i],ans_b[i]);
	}
	puts("");
	return 0;
}