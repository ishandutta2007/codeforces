#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 32;
const int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

vector<int> E[MAXN];
ll x[MAXN], y[MAXN];

void Draw(int u, int pre, int di, ll s){
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i]) == pre)
			continue;
		di = di + 1 & 3;
		x[v] = x[u] + s * d[di][0], y[v] = y[u] + s * d[di][1];
		Draw(v, u, di + 2 & 3, s >> 1);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		if (E[i].size() > 4){
			puts("NO");
			return 0;
		}
	Draw(1, 0, 0, 1ll << 58);
	puts("YES");
	for (int i = 1; i <= n; ++i)
		printf("%lld %lld\n", x[i], y[i]);
	return 0;
}