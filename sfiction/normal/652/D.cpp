#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 2E5 + 10;

int n;
int a[MAXN], b[MAXN];
int l[MAXN];
PII r[MAXN];

int sum[MAXN];

int update(int i){
	for (; i <= n; i = (i | i - 1) + 1)
		++sum[i];
}

int query(int i){
	int ret = 0;
	for (; 0 < i; i &= i - 1)
		ret += sum[i];
	return ret;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &a[i], &r[i].st);
		l[i] = a[i];
		r[i].nd = i;
	}
	sort(l, l + n);
	sort(r, r + n);
	for (int i = 0; i < n; ++i){
		int t = lower_bound(l, l + n, a[r[i].nd]) - l;
		b[r[i].nd] = i - query(t);
		update(t + 1);
	}
	for (int i = 0; i < n; ++i)
		printf("%d\n", b[i]);
	return 0;
}