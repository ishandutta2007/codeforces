#include <iostream>
using namespace std;
int n;
int main() {
	scanf("%d",&n);
	printf("YES\n");
	for(int i=1;i<=n;i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int f=0;
		if(x1%2==0)f|=1;
		if(y1%2==0)f|=2;
		f++;
		printf("%d\n", f);
	}
}