/*
ID: Sfiction
OJ: CF
PROB: 448A
*/
#include <cstdio>

int main(){
	int cup=0,medal=0;
	int n;

	for (int t,i=0;i<3;++i){
		scanf("%d",&t);
		cup+=t;
	}
	for (int t,i=0;i<3;++i){
		scanf("%d",&t);
		medal+=t;
	}

	scanf("%d",&n);
	puts(n>=(cup+4)/5+(medal+9)/10 ? "YES" : "NO");
	return 0;
}