#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 5E5 + 10;

PII a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].nd, &a[i].st);
	sort(a, a + n);

	int right = -1, ans = 0;
	for (int i = 0; i < n; ++i)
		if (right < a[i].nd){
			++ans;
			right = a[i].st;
		}
	printf("%d\n", ans);
	return 0;
}