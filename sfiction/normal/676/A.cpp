#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n, a, b;
	scanf("%d", &n);
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		a = t == 1 ? i : a;
		b = t == n ? i : b;
	}
	printf("%d\n", a == 1 || a == n || b == 1 || b == n ? n - 1 : max(max(n - a, a - 1), max(n - b, b - 1)));
	return 0;
}