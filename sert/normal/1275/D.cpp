#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int B = 1000;
const int N = (int)1e6 + 34;

struct SEG {
	int l, r, ind;
	explicit SEG(int l = 0, int r = 0, int ind = 0): l(l), r(r), ind(ind) {}
	bool operator<(const SEG &seg) const {
		return l < seg.l;
	}
};

struct FW {
    vector<ll> sum;
    int sz;
    explicit FW(int sz) {
        this->sz = sz;
        sum.resize(sz);
        for (auto &x : sum) x = 0;
    }

    void add(int pos, ll x) {
        //cout << "add " << pos << " " << x << endl;
        for (; pos < sz; pos |= (pos + 1)) sum[pos] += x;
    }

    ll pref(int pos) {
        if (pos < 0) return 0;
        ll res = 0;
        for(; pos >= 0; pos = (pos & (pos + 1)) - 1) res += sum[pos];
        return res;
    }

    ll getSum(int l, int r) {
        //cout << "getsum  " << l << " " << r << endl;
        return pref(r) - pref(l - 1);
    }
};

void solve_big(const vector<int> &a, int val, const vector<SEG> &seg, vector<ll> &ans) {
	int n = a.size();
	vector<int> sum(n + 1, 0);
	for (int i = 0; i < n; i++) {
		sum[i + 1] = sum[i] + (a[i] == val ? 1 : 0);
	}
	for (const SEG &s : seg) {
		ll num = sum[s.r + 1] - sum[s.l];
		ans[s.ind] += num * num * val;
	}
}

void solve_small(const vector<int> &a, const vector<SEG> &seg, vector<ll> &ans) {
	int n = a.size();
	vector<ll> score(n + 2, 0);
	vector<ll> sub(n + 2, 0);
	vector<ll> num(N, 0);
	vector<int> nxt(n, -1);
	vector<int> lst(N, -1);
	for (int i = 0; i < n; i++) {
		score[i] = (i == 0 ? 0 : score[i - 1]);
		if (a[i] == -1) continue;
		score[i] += (num[a[i]] * 2 + 1) * a[i];
		num[a[i]]++;

		if (lst[a[i]] != -1) nxt[lst[a[i]]] = i;
		lst[a[i]] = i;
	}

	int cur_seg = 0;

	FW fw(n + 1);
	for (int i = 0; i < n; i++) {
		for (; cur_seg < (int)seg.size() && seg[cur_seg].l == i; cur_seg++) {
			const SEG &s = seg[cur_seg];
			ans[s.ind] += score[s.r] - fw.pref(s.r);
		}
        if (a[i] == -1) continue;

		int pos = i;

		fw.add(pos, a[i]);
		while (nxt[pos] != -1) {
			pos = nxt[pos];
			fw.add(pos, a[i] * 2);
		}
	}
}

void solve() {
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	vector<int> num(N, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		num[a[i]]++;
	}

	vector<SEG> seg;
	for (int i = 0; i < t; i++) {
		int l, r;
		cin >> l >> r;
		seg.emplace_back(l - 1, r - 1, i);
	}
	sort(seg.begin(), seg.end());
	vector<ll> ans(t, 0);

	for (int i = 0; i < N; i++) {
		if (num[i] > B) {
			solve_big(a, i, seg, ans);
		}
	}
	for (int i = 0; i < n; i++) {
		if (num[a[i]] > B) a[i] = -1;
	}
	solve_small(a, seg, ans);

	for (int i = 0; i < t; i++) {
		cout << ans[i] << "\n";
	}
}

int main() {
    //freopen("a.in", "r", stdin);
  	ios::sync_with_stdio(false);
  	cin.tie(nullptr);
  	//solve();
  	solve();
}