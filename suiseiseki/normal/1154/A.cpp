#include <cstdio>
#include <algorithm>
using namespace std;
int x[10];
int main(){
	for(int i=1;i<=4;i++){
		scanf("%d",&x[i]);
	}
	sort(x+1,x+5);
	printf("%d %d %d\n",x[4]-x[1],x[4]-x[2],x[4]-x[3]);
	return 0;
}