// \_()_/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll SQ = 320;

int n, q, cnt[SQ + 10][MAXN], last_ans;
deque<int> S[SQ + 10];

inline void Shift(int L, int R) {
	int I_L = L / SQ, I_R = R / SQ, t = *next(S[I_R].begin(), R % SQ);	
	
	S[I_R].erase(next(S[I_R].begin(), R % SQ));
	cnt[I_R][t]--;
	for (int i = I_R; i > I_L; i--) {
		S[i].push_front(S[i - 1].back());
		cnt[i][S[i - 1].back()]++;
		cnt[i - 1][S[i - 1].back()]--;
		S[i - 1].pop_back();
	}

	S[I_L].insert(next(S[I_L].begin(), L % SQ), t);
	cnt[I_L][t]++;
}	

inline int Count(int L, int R, int k) {
	int I_L = L / SQ, I_R = R / SQ, ans = 0;
	if (I_L == I_R) {
		auto it = next(S[I_L].begin(), L % SQ);
		int cnt = R - L + 1;
		while (cnt--) {
			if (*it == k) ans++;
			it++;
		}	
		
		return ans;
	}


	for (int i = I_L + 1; i < I_R; i++) ans += cnt[i][k];
	ans += Count(L, (I_L + 1) * SQ - 1, k);
	ans += Count(I_R * SQ, R, k);	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[i / SQ][x]++;
		S[i / SQ].push_back(x);
	}
	
	cin >> q;
	while (q--) {
		int c, tl, tr, tk, l, r, k;
		cin >> c >> tl >> tr;
		l = (tl + last_ans + n - 1) % n, r = (tr + last_ans + n - 1) % n;
		if (l > r) swap(l, r);

		if (c == 1) Shift(l, r);	
		else {
			cin >> tk;
			k = (tk + last_ans + n - 1) % n + 1;
			cout << (last_ans = Count(l, r, k)) << endl;
		}
	}
	return 0;
}