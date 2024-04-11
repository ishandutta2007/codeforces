#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 3e5 + 7;
const int SQ = sqrt(MAXN);

struct Query {
	int l, r, id;
};

bool operator<(Query a, Query b) {
	if (a.l / SQ != b.l / SQ) {
		return a.l / SQ < b.l / SQ;
	}
	return a.r < b.r;
}

int main() {
	//freopen("F.in", "r", stdin);
	//freopen("F.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <pair <int, int> > elems; 
	vector <int> sz(1, 0);
	map <pair <int, int>, int> num;
	set <pair <int, int> > es;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		int sx, sy;
		int px, py;
		cin >> px >> py;
		sx = px, sy = py;
		for (int j = 0; j < k; j++) {
			int x, y;
			if (j != k - 1) {
				cin >> x >> y;
			} else {
				x = sx, y = sy;
			}
			int a = x - px, b = y - py;
			int g = __gcd(abs(a), abs(b));
			a /= g, b /= g;
			px = x, py = y;
			elems.push_back({a, b});
			es.insert({a, b});
		}
		sz.push_back(sz.back() + k);
	}
	int cnt = 0;
	for (auto x : es) {
		num[x] = cnt++;
	}
	vector <int> a;
	for (auto x : elems) {
		a.push_back(num[x]);
	}
	/*for (int x : a) {
		cout << x << " ";
	}*/
	cout << "\n";
	int q;
	cin >> q;
	vector <Query> qu(q);
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		qu[i] = {sz[l - 1], sz[r] - 1, i};
	}
	vector <int> freq(cnt, 0);
	int now = 0;
	sort(qu.begin(), qu.end());
	int lt = 0, rt = -1;
	vector <int> res(q, 0);
	for (auto t : qu) {
		//cout << t.l << " " << t.r << "\n";
		while (lt > t.l) {
			lt--;
			freq[a[lt]]++;
			if (freq[a[lt]] == 1) {
				now++;
			}
		}
		while (rt < t.r) {
			rt++;
			freq[a[rt]]++;
			if (freq[a[rt]] == 1) {
				now++;
			}
		}
		while (lt < t.l) {
			freq[a[lt]]--;
			if (freq[a[lt]] == 0) {
				now--;
			}
			lt++;
		}
		while (rt > t.r) {
			freq[a[rt]]--;
			if (freq[a[rt]] == 0) {
				now--;
			}
			rt--;
		}
		res[t.id] = now;
	}
	for (int x : res) {
		cout << x << "\n";
	}
}