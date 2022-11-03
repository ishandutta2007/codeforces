#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 1E3 + 10;

int n;
int a[MAXN];
int b[MAXN];

unordered_map<int, int> lst;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if (!lst.count(a[i]))
			lst[a[i]] = 0;
		++lst[a[i]];
	}
	int ans = lst.count(0) ? lst[0] : 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j && (a[i] || a[j])){
				--lst[a[i]], --lst[a[j]];
				b[0] = a[i], b[1] = a[j];
				int k = 2;
				for (; lst.count(b[k] = b[k - 1] + b[k - 2]) && lst[b[k]]; --lst[b[k++]]);
				ans = max(ans, k);
				for (; --k >= 0; ++lst[b[k]]);
			}
	printf("%d\n", ans);
	return 0;
}