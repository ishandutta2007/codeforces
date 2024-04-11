#include <cstdio>
#include <cstring>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 2e5 + 100;

int t, n, s[N], f[N], g[N];
char str[N];

int tree[3][N << 1], neg[3][N << 1];

void add(int *tree, int i){
	i += n + 10;
	while(i <= 2 * n + 20){
		tree[i]++;
		i += lowbit(i);
	}
}

int sum(int *tree, int i){
	int ret = 0;
	i += n + 10;
	while(i){
		ret += tree[i];
		i -= lowbit(i);
	}
	return ret;
}

int main(){
	scanf("%d", &t);
	while(t--){
		memset(s, 0, sizeof(int) * (n + 1));
		memset(f, 0, sizeof(int) * (n + 1));
		memset(g, 0, sizeof(int) * (n + 1));
		for(int i = 0; i < 3; i++)
			memset(tree[i] + 1, 0, sizeof(int) * (2 * n + 40)), memset(neg[i] + 1, 0, sizeof(int) * (2 * n + 40));
		scanf("%d%s", &n, str + 1);
		for(int i = 1; i <= n; i++){
			if(str[i] == '+') s[i] = s[i - 1] - 1;
			else s[i] = s[i - 1] + 1;
			if(str[i] == '-' && str[i - 1] == '-') f[i] = f[i - 2] + 1;
			else f[i] = f[i - 1];
			if(str[i] == '-' && str[i + 1] == '-') g[i] = f[i - 1] + 1;
			else g[i] = g[i - 1];
		}
		add(tree[0], 0);
		add(neg[0], 0);
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			ans += sum(tree[(s[i] % 3 + 3) % 3], f[i] - (s[i] + 3 * n) / 3 + n) - sum(neg[(s[i] % 3 + 3) % 3], -1 - s[i]);
			add(tree[(s[i] % 3 + 3) % 3], g[i] - (s[i] + 3 * n) / 3 + n);
			add(neg[(s[i] % 3 + 3) % 3], - s[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}