#include <cstdio>
#define Maxn 1000
int n,m;
bool d[Maxn+5];
struct P{
	int t,l,r;
}a[Maxn+5];
int ans[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].r);
		if(a[i].t==1){
			for(int j=a[i].l;j<a[i].r;j++){
				d[j]=1;
			}
		}
	}
	bool have;
	for(int i=1;i<=m;i++){
		if(a[i].t==0){
			have=1;
			for(int j=a[i].l;j<a[i].r;j++){
				if(!d[j]){
					have=0;
					break;
				}
			}
			if(have){
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	ans[1]=400000;
	for(int i=1;i<n;i++){
		if(d[i]){
			ans[i+1]=ans[i]+1;
		}
		else{
			ans[i+1]=ans[i]-1;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}