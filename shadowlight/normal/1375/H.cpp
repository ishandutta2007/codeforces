#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = (1 << 12) + 7;
const int Q = (1 << 16) + 7;
const int S = sqrt(Q);

int total;
vector <pair <int, int> > merged;

int merge(int v, int u) {
	if (v == -1 || u == -1) {
		return v + u + 1;
	}
	merged.pb({v, u});
	return total++;
}

vector <int> b;

vector <vector<int>> rec(vector<int>& block, int l, int r) {
	int n = block.size();
	vector <vector<int>> res(n + 1, vector<int> (n + 1, -1));
	if (!n) {
		return res;
	}
	if (r - l == 1) {
		assert(n == 1);
		res[0][1] = block[0];
		//cout << "KEKU " << block[0] << endl;
		return res;
	}
	int mid = (l + r) / 2;
	vector <int> lblock, rblock;
	for (int x : block) {
		if (b[x] < mid) {
			lblock.pb(x);
		} else {
			rblock.pb(x);
		}
	}
	auto lseg = rec(lblock, l, mid);
	auto rseg = rec(rblock, mid, r);

	int l_left = 0, l_right = 0;

	for (int i = 0; i < n; ++i) {
		int r_left = l_left, r_right = l_right;
		for (int j = i; j < n; ++j) {
			if (b[block[j]] < mid) {
				++r_left;
			} else {
				++r_right;
			}
			//cout << mid << " " << b[block[j]] << endl;
			//cout << l_left << " " << r_left << " " << l_right << " " << r_right << " " << lblock.size() << " " << rblock.size() << endl;
			//cout << "KEKW: " << l << " " << r << " " << i << " " << j << " " << lseg[l_left][r_left] << " " << rseg[l_right][r_right] << endl;
			res[i][j + 1] = merge(lseg[l_left][r_left], rseg[l_right][r_right]);
		}
		if (b[block[i]] < mid) {
			++l_left;
		} else {
			++l_right;
		}
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("O_input.txt", "r", stdin);
	//freopen("O_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	total = n;
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x;
		a[i].y = i;
	}
	sort(all(a));
	b.resize(n);
	for (int i = 0; i < n; ++i) {
		b[a[i].y] = i;
	}

	vector<vector<int>> blocks;
	vector<vector<vector<int>>> idxs;
	vector <int> pos(n, -1);
	for (int i = 0; i < n; i += S) {
		vector <int> block;
		for (int j = 0; j < n; ++j) {
			if (i <= b[j] && b[j] < i + S) {
				block.pb(j);
			}
		}
		blocks.pb(block);
		idxs.pb(rec(block, i, i + S));	
	}

	vector <int> res(q, -1);

	for (int it = 0; it < q; ++it) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		int now = -1;
		int cur = 0;
		for (int i = 0; i < n; i += S) {
			int lv = lower_bound(all(blocks[cur]), l) - blocks[cur].begin();
			int rv = upper_bound(all(blocks[cur]), r) - blocks[cur].begin();

			//cout << "KEKW " << now << " " << idxs[cur][lv][rv] << endl;

			now = merge(now, idxs[cur][lv][rv]);
			++cur;
		}
		res[it] = now;
	}

	cout << total << endl;
	for (auto t : merged) {
		cout << t.x + 1 << " " << t.y + 1 << "\n";
	}

	for (int i = 0; i < q; ++i) {
		cout << res[i] + 1 << " ";
	}
	cout << "\n";
}