#include <cstdio>
#include <cstring>
#define le (i << 1)
#define ri (i << 1 | 1)
using namespace std;
const int N = 2e5 + 1, p = 1e9 + 7;
const unsigned int INF = 0xFFFFFFFF;

unsigned int tree[N << 2], L, R, X, a[N];

void andset(int i, int l, int r){
	if(l >= L && r <= R){
		tree[i] &= X;
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= L) andset(le, l, mid);
	if(mid < R) andset(ri, mid + 1, r);
}

void pushall(int i, int l, int r){
	if(l == r){
		a[l] = tree[i];
		return;
	}
	tree[le] &= tree[i];
	tree[ri] &= tree[i];
	int mid = (l + r) >> 1;
	pushall(le, l, mid);
	pushall(ri, mid + 1, r);
}

int t, n, m, cnt[N][30][2], ans;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		memset(cnt + 1, 0, sizeof(int) * 30 * 2 * n);
		scanf("%d%d", &n, &m);
		memset(tree + 1, 0xff, sizeof(unsigned int) * (n << 2));
		while(m--){
			scanf("%u%u%u", &L, &R, &X);
			andset(1, 1, n);
		}
		pushall(1, 1, n);
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < 30; j++){
				if((a[i] >> j) & 1){
					cnt[i][j][1] = (cnt[i - 1][j][1] + cnt[i - 1][j][0] + 1) % p;
					cnt[i][j][0] = (cnt[i - 1][j][0] + cnt[i - 1][j][1]) % p;
				}else{
					cnt[i][j][1] = (cnt[i - 1][j][1] << 1) % p;
					cnt[i][j][0] = ((cnt[i - 1][j][0] << 1) + 1) % p;
				}
			}
		for(int j = 0; j < 30; j++)
			ans = (ans + (1ll << j) * cnt[n][j][1]) % p;
		printf("%d\n", ans);
	}
	return 0;
}