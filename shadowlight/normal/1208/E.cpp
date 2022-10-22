#include <bits/stdc++.h>
#define ll long long
#define db long double
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1e6 + 7;
const ll INF = 1e12 + 7;

ll t[4 * N];

int n;

void add_seg(int l, int r, ll x, int lt = 0, int rt = n, int vt = 1) {
	if (lt >= r || l >= rt) {
		return;
	}
	if (l <= lt && rt <= r) {
		t[vt] += x;
		return;
	}
	int mt = (lt + rt) / 2;
	add_seg(l, r, x, lt, mt, 2 * vt);
	add_seg(l, r, x, mt, rt, 2 * vt + 1);
}

ll get(int pos, int lt = 0, int rt = n, int vt = 1) {
	if (pos >= rt || pos < lt) {
		return 0;
	}
	if (rt - lt == 1) {
		return t[vt];
	}
	int mt = (lt + rt) / 2;
	ll x = get(pos, lt, mt, 2 * vt);
	ll y = get(pos, mt, rt, 2 * vt + 1);
	return x + y + t[vt];
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		int len;
		cin >> len;
		vector <pair <int, int> > a(len);
		for (int j = 0; j < len; j++) {
			int x;
			cin >> x;
			a[j] = {x, j};
		}
		sort(a.rbegin(), a.rend());
		set <int> starts, ends;
		//cout << "kek\n";
		int tp = 0;
		for (int j = 0; j < len; j++) {
			int pos = a[j].second, value = a[j].first;
			int lt = pos, rt = n - (len - pos);
			if (a[j].first < 0) {
				if (!tp) {
					j--;
					lt = -1, rt = n - len - 1;
					value = 0;
					tp++;
				} else if (tp == 1) {
					j--;
					lt = len, rt = n;
					value = 0;
					tp++;
				}
			}
			int stl = lt, str = rt;
			//cout << "penis " << lt << " " << rt << " " << value << "\n";
			auto it = starts.lower_bound(stl);
			if (it != starts.end() && *it <= rt) {
				rt = *it - 1;
			}
			it = ends.upper_bound(str);
			if (it != ends.begin()) {
				it--;
				if (*it >= lt) {
					lt = *it + 1;
				}
			}
			//cout << lt << " " << rt << "\n";
			if (lt <= rt) {
				//cout << lt << " " << rt << " " << value << "\n";
				starts.insert(stl);
				ends.insert(str);
				add_seg(lt, rt + 1, value);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << get(i) << " ";
	}
	cout << "\n";

}