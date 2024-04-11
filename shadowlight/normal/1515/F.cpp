#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n, m;
ll xx;

struct Component {
	ll w;
	vector<int> vs;
	vector <int> total;
};

const int N = 3e5 + 7;
int num[N];
Component comps[N];

int merge(int x, int y) {
	assert(x != y);  
	auto &a = comps[x];
	auto &b = comps[y];

	if (a.total.size() > b.total.size()) {
		a.w = a.w + b.w - xx;
		for (int val : b.vs) {
			a.vs.pb(val);
		}
		for (int val : b.total) {
			a.total.pb(val);
			num[val] = x;
		}
		b.vs.clear();
		return x;
	}
	b.w = a.w + b.w - xx;
	for (int val : a.vs) {
		b.vs.pb(val);
		num[val] = y;
	}
	for (int val : a.total) {
		b.total.pb(val);
		num[val] = y;
	}
	a.vs.clear();
	return y;
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> xx;
	vector <ll> a(n);
	ll sum = 0;
	set <pair <ll, int>> q;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		q.insert({a[i], i});
		comps[i] = {a[i], {i}, {i}};
		num[i] = i;
	}

	if (sum < (n - 1) * xx) {
		cout << "NO\n";
		return 0;
	}

	vector <vector <pair<int, int>>> gr(n);
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		gr[v].pb({u, i});
		gr[u].pb({v, i});
	}
	vector<int> iter(n, 0);
	int now = 0;

	int merged = 0;

	cout << "YES\n";
	while (q.size() > 1) {
		int index = q.rbegin()->y;
		assert(comps[index].vs.size() <= n);

		/*for (int i = 0; i < n; ++i) {
			cout << num[i] << " ";
		}
		cout << endl;*/

		while (comps[index].vs.size()) {
			int v = comps[index].vs.back();
			bool bad = true;

			while (iter[v] < gr[v].size()) {
				int u = gr[v][iter[v]].x;
				int id = gr[v][iter[v]++].y;

				if (num[u] == index) continue;
				cout << id + 1 << "\n";
				++merged;
				
				q.erase({comps[index].w, index});
				
				int pos = num[u];

				//assert(q.find({comps[pos].w, pos}) != q.end());
				q.erase({comps[num[u]].w, num[u]});

				index = merge(index, pos);

				q.insert({comps[index].w, index});
				bad = false;
				break;
			}
			if (bad) {
				comps[index].vs.pop_back();
			} else {
				break;
			}
		}
	}

}