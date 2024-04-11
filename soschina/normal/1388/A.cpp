#include <cstdio>
using namespace std;
//6, 10, 14, 15
int t, n, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n > 30){
			puts("YES");
			x = n - 30;
			if(x == 6 || x == 10 || x == 14) printf("%d %d %d %d\n", 6, 10, 15, x - 1);
			else printf("%d %d %d %d\n", 6, 10, 14, x);
		}
		else puts("NO");
	}
	return 0;
}