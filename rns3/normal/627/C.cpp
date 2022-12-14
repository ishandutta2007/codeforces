#include <bits/stdc++.h>
using namespace std;
#define M 200200
typedef long long ll;

int n;
int dist;
int once;
pair<int, int> p[M];
int nxt[M];

ll solve() {
	ll cur = 0, gas = once;
	ll answer = 0;

	while (cur < n) {
		//printf("cur = %d, n = %d\n", cur, n);
		int d = p[cur+1].first - p[cur].first;
		if (d > once) {
			return -1;
		}
		if (d > gas) {
			answer += 1ll * p[cur].second * (d - gas);
			gas = d;
		}

		int i = nxt[cur];
		if (p[i].first - p[cur].first < once) {
			if (p[i].first - p[cur].first > gas) {
				answer += 1ll * p[cur].second * (p[i].first - p[cur].first - gas);
				gas = p[i].first - p[cur].first;
			}
		} else {
			answer += 1ll * p[cur].second * (once - gas);
			gas = once;
		}

		gas -= d;
		cur++;
	}
	return answer;
}

int main() {
	///freopen("C.in", "r", stdin);
    scanf("%d %d", &dist, &once);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
		scanf("%d %d", &p[i].first, &p[i].second);
    }
   	p[++n] = make_pair(dist, 0);

    sort(p + 1, p + n + 1);

	nxt[n] = n;
	//puts("T");
    for (int i = n - 1; i >= 1; i--) {
		int k = i + 1;
		while (p[k].second > p[i].second) {
			k = nxt[k];
		}
		nxt[i] = k;
		//printf("nxt[%d] = %d\n", i, nxt[i]);
    }
    printf("%I64d\n", solve());
	return 0;
}