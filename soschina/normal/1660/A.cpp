#include <cstdio>
using namespace std;

int t, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		if(!a) puts("1");
		else printf("%d\n", a + 2 * b + 1);
	}
	return 0;
}