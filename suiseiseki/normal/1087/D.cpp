#include <cstdio>
#define Maxn 100000
int d[Maxn+5];
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		d[u]++;
		d[v]++;
	}
	int now=0;
	for(int i=1;i<=n;i++){
		if(d[i]==1){
			now++;
		}
	}
	printf("%.9lf\n",s*1.0/now*2.0);
	return 0;
}