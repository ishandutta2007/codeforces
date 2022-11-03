#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 10;

int C;
int cnt[MAXN], nex[MAXN];

bool check(int val){
	int res = C, u = nex[C];
	for (; u >= val; u = nex[min(res, u - 1)])
		res -= min(cnt[u], res / u) * u;
	if (res > val)
		res -= val, u = nex[min(res, val - 1)];
	for (; u; u = min(res, u - 1))
		res -= min(cnt[u], res / u) * u;
	return !res;
}

int main(){
	int n;
	scanf("%d%d", &C, &n);
	for (int x, i = 0; i < n; ++i){
		scanf("%d", &x);
		++cnt[x];
	}
	for (int i = 1; i <= C; ++i)
		nex[i] = cnt[i] ? i : nex[i - 1];
	bool flag = false;
	for (int i = 2; i < C; ++i)
		if (!check(i)){
			printf("%d\n", i);
			flag = true;
			break;
		}
	if (!flag)
		puts("Greed is good");
	return 0;
}