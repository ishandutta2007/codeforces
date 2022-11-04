#include <cstdio>
using namespace std;
const int N = 101;

int t, n, a[N], ans[2];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", a + i);
		if(n == 1 && (a[1] & 1)) puts("-1");
		else if(!(a[1] & 1)) puts("1"), puts("1");
		else if(!(a[2] & 1)) puts("1"), puts("2");
		else puts("2"), puts("1 2");
	}
	return 0;
}