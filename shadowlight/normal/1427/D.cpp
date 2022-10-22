#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
vector <int> a;

vector <vector <int>> res;

void do_op(vector <int> sizes) {
	if (sizes.size() > 1) {
		res.pb(sizes);
	}
	vector <vector <int>> blocks;
	int l = 0;
	for (int sz : sizes) {
		int r = l + sz;
		assert(r <= n);
		vector <int> block;
		for (int i = l; i < r; ++i) {
			block.pb(a[i]);
		}
		blocks.pb(block);
		l = r;
	}
	assert(l == n);
	reverse(all(blocks));
	a.clear();
	for (auto block : blocks) {
		for (int x : block) {
			a.pb(x);
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int first = 1, last = n;
	for (int i = 0; i < n - 1; ++i) {
		int need = (i % 2 == 0 ? first : last);
		vector <int> sizes;
		int sz = 0;
		int found = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] < first || a[i] > last) {
				if (found && sz) {
					sizes.pb(sz);
					sz = 0;
					found = 2;
				} else if (!found && sz) {
					//cout << found << " " << sz << endl;
					assert(false);
				}
				sizes.pb(1);
				continue;
			}
			++sz;
			if (a[i] == need) {
				sizes.pb(sz);
				sz = 0;
				found = 1;
			}
		}
		if (found && sz) {
			assert(found == 1);
			sizes.pb(sz);
		}
		do_op(sizes);
		/*for (int x : a) {
			cout << x << " ";
		}
		cout << endl;*/
		if (need == first) {
			++first;
		} else {
			--last;
		}
	}
	if (a[0] != 1) {
		vector <int> sizes(n, 1);
		do_op(sizes);
	}
	auto b = a;
	sort(all(b));
	assert(b == a);

	assert(res.size() <= n);

	cout << res.size() << "\n";
	for (auto t : res) {
		cout << t.size() << " ";
		for (int x : t) {
			cout << x << " ";
		}
		cout << "\n";
	}

}