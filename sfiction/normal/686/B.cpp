#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E2 + 10;

int a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; ++i)
		for (int j = n - 1; j >= 1; --j)
			if (a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
				printf("%d %d\n", j, j + 1);
			}
	return 0;
}