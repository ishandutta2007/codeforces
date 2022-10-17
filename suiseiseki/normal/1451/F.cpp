#include <cstdio>
const int Maxn=200;
int val[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		bool flag=0;
		for(int i=1;i<=n+m;i++){
			val[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int x;
				scanf("%d",&x);
				val[i+j]^=x;
			}
		}
		for(int i=1;i<=n+m;i++){
			if(val[i]){
				flag=1;
			}
		}
		if(flag){
			puts("Ashish");
		}
		else{
			puts("Jeel");
		}
	}
	return 0;
}