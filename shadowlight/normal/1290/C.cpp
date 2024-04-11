#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 3e5 + 7;

int num[N], sz[N], cnt[N];
bool on[N], ways[N];

vector <int> in_sets[N];
vector <int> sets[N];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector <char> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	for (int i = 0; i < N; i++) {
		sz[i] = 1;
		ways[i] = true;
		sets[i].push_back(i);
		num[i] = i;
	}

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		for (int j = 0; j < c; j++) {
			int x;
			cin >> x;
			x--;
			in_sets[x].push_back(i);
		}
	}
	int iter = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		iter++;
		if (!in_sets[i].size()) {
			cout << res << "\n";
			continue;
		}
		if (in_sets[i].size() == 1) {
			int v = in_sets[i][0], t = num[v];
			if (!ways[t]) {
				cout << res << "\n";
				continue;
			}
			ways[t] = false;
			res -= min(sz[t] - cnt[t], cnt[t]);
			if (((s[i] - '0') ^ on[v]) != 1) {
				cnt[t] = sz[t] - cnt[t];
				for (int x : sets[t]) {
					on[x] = 1 - on[x];
				}
			}
			res += cnt[t];
		} else {
			int v = in_sets[i][0], u = in_sets[i][1];
			int t = num[v], tn = num[u];
			if (sz[t] > sz[tn]) {
				swap(v, u);
				swap(t, tn);
			}
			if (t == tn) {
				cout << res << "\n";
				continue;
			}
			res -= (ways[t] ? min(cnt[t], sz[t] - cnt[t]) : cnt[t]);
			res -= (ways[tn] ? min(cnt[tn], sz[tn] - cnt[tn]) : cnt[tn]);
			if (((on[v] + on[u] + (s[i] - '0')) % 2) != 1) {
				int need = t;
				if (!ways[need]) {
					need = tn;
				}
				cnt[need] = sz[need] - cnt[need];
				for (int x : sets[need]) {
					on[x] = 1 - on[x];
				}
			}
			while (sets[t].size()) {
				int x = sets[t].back();
				sets[tn].push_back(x);
				num[x] = tn;
				sets[t].pop_back();
			}
			sz[tn] += sz[t];
			cnt[tn] += cnt[t];
			if (!ways[t]) {
				ways[tn] = false;
			}
			res += (ways[tn] ? min(cnt[tn], sz[tn] - cnt[tn]) : cnt[tn]);
		}
		cout << res << "\n";
		/*cout << "SETS:\n";
		for (int i = 0; i < k; i++) {
			if (sets[i].size()) {
				for (int x : sets[i]) {
					cout << x << " ";
				}
				cout << endl;
			}
		}
		cout << "===\n";*/
	}

}