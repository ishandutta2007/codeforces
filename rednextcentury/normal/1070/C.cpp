#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000100

pair<ll, ll> seg[N * 5];
void update(int i, ll val, int p = 1, int L = 0, int R = N){
	if (i < L || i > R) return;
	if (L == R){
		seg[p].first += val;
		seg[p].second += L * val;
		return;
	}

	int mid = (L + R) / 2;
	update(i, val, p * 2, L, mid);
	update(i, val, p * 2 + 1, mid + 1, R);
	seg[p].first = seg[p * 2].first + seg[p * 2 + 1].first;
	seg[p].second = seg[p * 2].second + seg[p * 2 + 1].second;
}

ll query(ll need, int p = 1, int L = 0, int R = N){
	if (need >= seg[p].first) return seg[p].second;
	if (L == R) return need * L;

	int mid = (L + R) / 2;
	if (seg[p * 2].first >= need) return query(need, p * 2, L, mid);
	else return seg[p * 2].second + query(need - seg[p * 2].first, p * 2 + 1, mid + 1, R);
}

vector<pair<ll, ll> > offer[N];

int main(){
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	
	for (int i = 0; i < N * 5; i++) seg[i] = make_pair(0, 0);
	int n, k, m; cin >> n >> k >> m;
	while (m--){
		int L, R, c, p; cin >> L >> R >> c >> p;
		offer[L].push_back(make_pair(c, p));
		offer[R + 1].push_back(make_pair(-c, p));
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < (int)offer[i].size(); j++){
			ll c = offer[i][j].first, p = offer[i][j].second;
			update(p, c);
		}
		ans += query(k);
	}
	cout << ans << endl;

	return 0;
}