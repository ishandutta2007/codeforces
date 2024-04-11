#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 5E5 + 10;
const ll MOD = 1E9 + 7;

int n, h, w;
char s[MAXN];
int dx[MAXN], dy[MAXN];
int nex[MAXN], cnt[MAXN];

int main(){
	scanf("%d%d%d", &n, &w, &h);
	scanf("%s", s);
	for (int i = 0; i < n; ++i){
		cnt[i] = 1;
		dx[i] = s[i] == 'L' ? -1 : s[i] == 'R' ? 1 : 0;
		dy[i] = s[i] == 'D' ? -1 : s[i] == 'U' ? 1 : 0;
	}
	for (int i = n -  2; i >= 0; --i)
		nex[i] = i + 1;
	nex[n - 1] = 0;

	int u = n - 1, v;
	int ax, ay, bx, by;
	int x, y;
	ax = ay = bx = by = 0;
	x = y = 0;
	ll ans = 0;
	while ((h - bx + ax) && (w - by + ay)){
		v = nex[u];
		x += dx[v], y += dy[v];
		if (x < ax || bx < x || y < ay || by < y){
			ans = (ans + (ll)cnt[v] * (h - bx + ax) * (w - by + ay)) % MOD;
			ax = min(ax, x);
			bx = max(bx, x);
			ay = min(ay, y);
			by = max(by, y);
			u = v;
		}
		else if (u != v){
			x -= dx[v], y -= dy[v];
			nex[u] = nex[v];
			cnt[nex[u]] += cnt[v];
			dx[nex[u]] += dx[v], dy[nex[u]] += dy[v];
		}
		else{
			ans = -1;
			break;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}