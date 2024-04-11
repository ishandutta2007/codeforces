#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 1e6L + 11;

int d[N], s[N], t[N], c[N];
struct eve {
	int d, t, cid, c;
}e[N];

vector <eve> v[N];

int ic[N];
ll pre[N], suf[N];

int main() {
	int n, m, k; cin >> n >> m >> k;
	
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d%d%d", d + i, s + i, t + i, c + i);
		if(!t[i])
			e[i] = {d[i], 0, s[i], c[i]};
		else
			e[i] = {d[i], 1, t[i], c[i]};
		v[d[i]].pb(e[i]);
	}
	
	int cnt = 0; ll sum = 0;
	fill(ic, ic + N, -1);
	for(int i = 0; i < N; i ++) {
		for(eve e : v[i]) if(e.t == 0) {
			if(ic[e.cid] == -1) {
				ic[e.cid] = e.c;
				sum += e.c;
				cnt ++;
			} else if(ic[e.cid] > e.c) {
				sum -= ic[e.cid] - e.c;
				ic[e.cid] = e.c;
			}
		}
		if(cnt == n)
			pre[i] = sum;
		else
			pre[i] = -1;
	}
	cnt = 0; sum = 0;
	fill(ic, ic + N, -1);
	for(int i = N - 1; i >= 0; i --) {
		for(eve e : v[i]) if(e.t == 1) {
			if(ic[e.cid] == -1) {
				ic[e.cid] = e.c;
				sum += e.c;
				cnt ++;
			} else if(ic[e.cid] > e.c) {
				sum -= ic[e.cid] - e.c;
				ic[e.cid] = e.c;
			}
		}
		if(cnt == n)
			suf[i] = sum;
		else
			suf[i] = -1;
	}
	
	//for(int i = 1; i <= 20; i ++)
		//cout << pre[i] << ' ' << suf[i] << '\n';
	
	ll ans = -1;
	for(int i = 0; i + k + 1 < N; i ++) if(~pre[i] && ~suf[i + k + 1]) {
		if(!~ans || ans > pre[i] + suf[i + k + 1])
			ans = pre[i] + suf[i + k + 1];
	}
	cout << ans << '\n';
	
	return 0;
}