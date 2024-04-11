#include <cstdio>
#include <algorithm>
using namespace std;

int t, x[3];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", x, x + 1, x + 2);
		sort(x, x + 3);
		if(x[1] != x[2]){
			puts("NO");
			continue;
		}
		puts("YES");
		if(x[0] == x[1]) printf("%d %d %d\n", *x, *x, *x);
		else printf("%d %d %d\n", x[2], x[0], x[0]);
	}
	return 0;
}