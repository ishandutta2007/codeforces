#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 2E3 + 10;

int n, m, p;
int a[MAXN], b[MAXN];

bool check(int limit){
	static int vis[MAXN];
	fill_n(vis, m, false);
	for (int i = 0; i < n; ++i){
		bool flag = false;
		for (int j = 0; j < m; ++j)
			if (!vis[j] && abs(a[i] - b[j]) + abs(b[j] - p) <= limit){
				vis[j] = true;
				flag = true;
				break;
			}
		if (!flag)
			return false;
	}
	return true;
}

int main(){
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", b + i);
	sort(a, a + n);
	sort(b, b + m);
	int low = 0, high = 2e9;
	while (low < high){
		int mid = low + (high - low >> 1);
		if (check(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%d\n", low);
	return 0;
}