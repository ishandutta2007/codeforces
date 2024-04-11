#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E3 + 10;

int a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int val = 0;
	for (int j, i = 0; i < n; i = j){
		for (j = i + 1; j < n && a[i] == a[j]; ++j);
		val = max(val, j - i);
	}
	printf("%d\n", n - val);
	return 0;
}