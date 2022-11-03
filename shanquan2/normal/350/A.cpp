#include<cstdio>
using namespace std;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int cmin=2147483647,cmax=0;
	int wmin=cmin;
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		if(x<cmin)cmin=x;
		if(x>cmax)cmax=x;
	}
	for(int i=0;i<m;i++){
		int x;scanf("%d",&x);
		if(x<wmin)wmin=x;
	}
	if(cmax>=wmin || 2*cmin>=wmin)
		printf("-1\n");
	else if(cmax>2*cmin)
		printf("%d\n",cmax);
	else printf("%d\n",2*cmin);
	return 0;
}