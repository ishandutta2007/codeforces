#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 10;

int n, K, A, B, q;
int a[MAXN], b[MAXN];

int s1[MAXN], s2[MAXN];

void update(int s[], int i, int c){
	for (; i <= n; i = (i | i - 1) + 1)
		s[i] += c;
}

int query(int s[], int i){
	int ret = 0;
	for (; i > 0; i &= i - 1)
		ret += s[i];
	return ret;
}

int main(){
	scanf("%d%d%d%d%d", &n, &K, &A, &B, &q);
	for (int com, d, e, i = 0; i < q; ++i){
		scanf("%d%d", &com, &d);
		if (com == 1){
			scanf("%d", &e);
			update(s1, d, min(A, a[d] + e) - a[d]);
			update(s2, d, min(B, b[d] + e) - b[d]);
			a[d] = min(A, a[d] + e);
			b[d] = min(B, b[d] + e);
		}
		else
			printf("%d\n", query(s2, d - 1) + query(s1, n) - query(s1, d + K - 1));
	}
	return 0;
}