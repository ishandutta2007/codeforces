#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const int MAXN = 1e5 + 10;
const int SQ = 315;

int cnt = 0, cnt2 = 0, l = 0, r = 0, n, q, A[MAXN], len[MAXN], ans[MAXN];
bool B[MAXN];
deque<int> dq[MAXN];
stack<int> st_in, st_out, st_set, tot;
vector<pll> Q[MAXN];

inline void add_r(int ind) {
	int x = A[ind];
	if (dq[x].empty()) {
		B[x] = true;
		dq[x].push_back(ind);
		cnt++;
		cnt2++;
	} else {
		int l = ind - dq[x].back();
		dq[x].push_back(ind);

		if (!len[x]) len[x] = l;
		else if (len[x] != l) cnt -= B[x], B[x] = false;
	}
}

inline void add_l(int ind) {
	int x = A[ind];
	tot.push(x);

	if (dq[x].empty()) {
		B[x] = true;
		st_in.push(x);
		dq[x].push_front(ind);
		cnt++;
		cnt2++;
	} else {
		if (!B[x]) return;
		int l = dq[x].front() - ind;
		dq[x].push_front(ind);

		if (!len[x]) len[x] = l, st_set.push(x);
		else if (len[x] != l) {
			cnt--;
			B[x] = false;
			st_out.push(x);
		}
	}
}

inline void clear() {
	while (!tot.empty()) {
		int x = tot.top();
		tot.pop();
		while (!dq[x].empty() && dq[x].front() < l) dq[x].pop_front();
	}

	while (!st_out.empty()) {
		int x = st_out.top();
		st_out.pop();
		B[x] = true;
		cnt++;
	}

	while (!st_set.empty()) {
		int x = st_set.top();
		st_set.pop();
		len[x] = 0;
	}


	while (!st_in.empty()) {
		int x = st_in.top();
		st_in.pop();
		cnt--;
		cnt2--;

		B[x] = false;
		len[x] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];

	cin >> q;
	for (int t = 0; t < q; t++) {
		int ql, qr;
		cin >> ql >> qr;
		ql--;
		qr--;

		if (qr - ql + 1 <= SQ) {
			l = r = qr;
			while (l >= ql) {
				add_l(l);
				l--;
			}
	
			ans[t] = cnt2 + (cnt == 0);
			
			l = MAXN;
			clear();
		} else Q[qr].push_back({t, ql});
	}

	l = 0;
	r = 0;
	while (l < n) {
		cnt = cnt2 = 0;
		for (int i = 0; i < MAXN; i++) {
			B[i] = false;
			len[i] = 0;
			dq[i].clear();
		}
		
		l = min(n - 1, l + SQ - 1);
		r = l;

		while (r < n) {
			add_r(r);
			for (pll e : Q[r]) {
				int ind = e.X, ql = e.Y;
				if (ql / SQ != l / SQ) continue;
	
				int pl = l;
				while (l > ql) {
					l--;
					add_l(l);
				}

				ans[ind] = cnt2 + (cnt == 0);

				l = pl;
				clear();	
			}

			r++;
		}

		l++;
	}

	for (int i = 0; i < q; i++) cout << ans[i] << endl;
	return 0;
}