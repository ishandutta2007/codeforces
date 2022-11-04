#include <cstdio>
#include <algorithm>
using namespace std;

int t, n, a[3], tmp;

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 0; i < 3; i++)
			scanf("%d", a + i);
		scanf("%d", &n);
		if(a[0] + a[1] + a[2] - 3 < n){
			puts("NO");
			continue;
		}
		sort(a, a + 3);
		if(a[2] - n  <= a[0] + a[1] + 1) puts("YES");
		else puts("NO");
	}
	return 0;
}