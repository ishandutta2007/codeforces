#include <cstdio>
const int Maxn=10000;
int n;
int a[Maxn+5];
int main(){
	scanf("%d",&n);
	int last=1;
	for(int i=2;i<=n;i++){
		printf("? %d %d\n",last,i);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		printf("? %d %d\n",i,last);
		fflush(stdout);
		int y;
		scanf("%d",&y);
		if(x<y){
			a[i]=y;
		}
		else{
			a[last]=x;
			last=i;
		}
	}
	a[last]=n;
	printf("!");
	for(int i=1;i<=n;i++){
		printf(" %d",a[i]);
	}
	puts("");
	fflush(stdout);
	return 0;
}