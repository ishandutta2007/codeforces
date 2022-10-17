#include <cstdio>
int main(){
	int n,m,v;
	scanf("%d%d%d",&n,&m,&v);
	if(m<n-1){
		return puts("-1"),0;
	}
	if(m>(n-1)*(n-2)/2+1){
		return puts("-1"),0;
	}
	m-=n-1;
	for(int i=1;i<=n;i++){
		if(i==v){
			continue;
		}
		printf("%d %d\n",i,v);
	}
	if(v!=n){
		for(int i=1;i<n&&m>0;i++){
			if(i==v){
				continue;
			}
			for(int j=i+1;j<n&&m>0;j++){
				if(j==v){
					continue;
				}
				m--;
				printf("%d %d\n",i,j);
			}
		}
	}
	else{
		for(int i=2;i<=n&&m>0;i++){
			if(i==v){
				continue;
			}
			for(int j=i+1;j<=n&&m>0;j++){
				if(j==v){
					continue;
				}
				m--;
				printf("%d %d\n",i,j);
			}
		}
	}
	return 0;
}