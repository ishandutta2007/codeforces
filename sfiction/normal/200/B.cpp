/*
ID: Sfiction
OJ: CF
PROB: 200B
*/
#include <cstdio>

int main(){
	int n,t;
	double sum=0;
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&t);
		sum+=t;
	}
	printf("%.12lf",sum/double(n));
	return 0;
}