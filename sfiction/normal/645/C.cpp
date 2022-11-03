#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

int n, m;
char s[MAXN];
int r, a[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	++m;

	r = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] == '0')
			a[r++] = i;
	int ans = n - 1;
	for (int i = 0; i + m <= r; ++i){
		int high = i + m, low = i, mid;
		while (low < high){
			mid = low + high >> 1;
			if (a[mid] - a[i] <= a[i + m - 1] - a[mid])
				low = mid + 1;
			else
				high = mid;
		}
		ans = min(ans, max(a[i + m - 1] - a[low], a[low] - a[i]));
		ans = min(ans, max(a[i + m - 1] - a[low - 1], a[low - 1] - a[i]));
	}
	printf("%d\n", ans);
	return 0;
}