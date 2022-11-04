#include <cstdio>
#include <algorithm>
#include <cstring>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 301;

int t, n, m, a[N * N], id[N * N], x[N * N], y[N * N], tmp[N * N], seat[N * N];

bool cmp(int x, int y){
	return a[x] != a[y] ? a[x] < a[y] : x > y;
}

int tree[N * N];
void add(int i){
	while(i <= n * m){
		tree[i]++;
		i += lowbit(i);
	}
}

int query(int i){
	int ret = 0;
	while(i){
		ret += tree[i];
		i -= lowbit(i);
	}
	return ret;
}

int main(){
	scanf("%d", &t);
	while(t--){
		memset(tree + 1, 0, sizeof(int) * n * m);
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++){
				int pos = (i - 1) * m + j;
				scanf("%d", a + pos), id[pos] = pos;
				x[pos] = i, y[pos] = j;
			}
		sort(id + 1, id + 1 + n * m, cmp);
		for(int i = 1; i <= n * m; i++){
			int j = i;
			while(j < n * m && a[id[j + 1]] == a[id[j]]) j++;
			if(x[i] != x[j]){
				int len1 = y[j];
				memcpy(tmp + j - len1 + 1, id + i, sizeof(int) * len1);
				int len2 = m - y[i] + 1;
				memcpy(tmp + i, id + j - len2 + 1, sizeof(int) * len2);
				memcpy(tmp + i + len2, id + i + len1, sizeof(int) * (j - i + 1 - len1 - len2));
				memcpy(id + i, tmp + i, sizeof(int) * (j - i + 1)); 
			}
			i = j;
		}
		for(int i = 1; i <= n * m; i++)
			seat[id[i]] = i;
		long long ans = 0;
		for(int i = 1; i <= n * m; i++){
			ans += query(seat[i]) - query((x[seat[i]] - 1) * m);
			add(seat[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}