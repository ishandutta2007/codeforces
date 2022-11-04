#include <cstdio>
using namespace std;

int t, x, y, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &x, &y, &a, &b);
		x = y - x;
		a += b;
		if(x % a == 0) printf("%d\n", x / a);
		else puts("-1");
	}
	return 0;
}