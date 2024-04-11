#include <stdio.h>
#include <cstring>
#include <ctime>
#include <algorithm>
using namespace std;
const int maxn = 500100;
struct Node{
	int id, nu, k, ans;
}ans[maxn];
int w[maxn], val[maxn], cnt[maxn], f[maxn];
int  cmp_val(Node &x, Node &y){
	if(x.nu != y.nu) return x.nu < y.nu;
	else if(x.k != y.k) return x.k < y.k;
	else return x.id < y.id;
}
bool cmp_id(Node &x, Node &y){
	return x.id < y.id;
}
int Read(){
	char s[20]; scanf("%s", s);
	int n = strlen(s), rnt = 0;
	for(int i = 0; i < n; i++)
		if(s[i] == '1')
			rnt |= (1 << i);
	return rnt;
}
int main(){
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	int mx = (1 << n);
	for(int k = 0; k < mx; k++)
		for(int i = 0; i < n; i++)
			if(k >> i & 1)
				val[k] += w[i];
	for(int k = 1; k <= m; k++)
		cnt[Read()]++;
	for(int i = 1; i <= q; i++){
		ans[i].nu = Read();
		scanf("%d", &ans[i].k);
		ans[i].id = i;
	}
	sort(ans + 1, ans + 1 + q, cmp_val);
	for(int i = 1; i <= q; i++)
		f[i] = ans[i].k;
//	printf("cnt3:%d\n", cnt[3]);
	for(int p = 1, Q = 1; p <= q; p = Q){
		while(ans[Q].nu == ans[p].nu) Q++;
//		printf("p:%d Q:%d\n", p, Q);
		for(int k = 0; k < mx; k++){
			int v = val[(mx - 1) ^ ans[p].nu ^ k];
			int pos = lower_bound(f + p, f + Q, v) - f;
//			printf("k:%d p:%d pos:%d c:%d v:%d\n", k, p, pos, cnt[k], v);
			if(pos < Q) ans[pos].ans += cnt[k];
		}
		for(int j = p + 1; j < Q; j++)
			ans[j].ans += ans[j-1].ans;

	}
	sort(ans + 1, ans + 1 + q, cmp_id);
	for(int i = 1; i <= q; i++)
		printf("%d\n", ans[i].ans);
	return 0;
}