#include <cstdio>
#define Maxn 500000
#define Maxm 700
int n,a[Maxn+5],r[Maxm+5][Maxm+5];
int main(){
	scanf("%d",&n);
	int t,x,y;
	int ans;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			a[x]+=y;
			for(int i=1;i<=Maxm;i++){
				r[i][x%i]+=y;
			}
		}
		else{
			if(x>Maxm){
				ans=0;
				for(int i=y;i<=Maxn;i+=x){
					ans+=a[i];
				}
				printf("%d\n",ans);
			}
			else{
				printf("%d\n",r[x][y]);
			}
		}
	}
	return 0;
}