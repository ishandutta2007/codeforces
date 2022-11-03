#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1E6 + 10;

int n, K;
int l[MAXN], r[MAXN];
PII a[MAXN << 1];

int main(){
	scanf("%d%d", &n, &K);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &a[i << 1].st, &a[i << 1 | 1].st);
		a[i << 1].nd = -1;
		a[i << 1 | 1].nd = 1;
	}
	int m = n << 1;
	sort(a, a + m);
	int cnt = 0;
	vector<PII> b;
	for (int i = 0; i < m; ++i){
		int pre = cnt;
		cnt -= a[i].nd;
		if (cnt >= K){
			if (pre < K)
				b.push_back(PII(a[i].st, a[i + 1].st));
			else
				b.back().nd = a[i + 1].st;
		}
	}
	printf("%d\n", b.size());
	for (int i = 0; i < b.size(); ++i)
		printf("%d %d\n", b[i].st, b[i].nd);
	return 0;
}