#include <cstdio>
#include <algorithm>
using namespace std;
int a[3];
int main(){
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	if(a[0]+a[1]>a[2]){
		puts("0");
	}
	else{
		printf("%d\n",a[2]+1-a[0]-a[1]);
	}
	return 0;
}