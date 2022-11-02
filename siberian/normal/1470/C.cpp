#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
#ifdef LOCAL
	//freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
  
	vector<int> v(n, k);

	vector<int> rem;
	for (int i = 0; i < n; ++i) rem.pb(i);

	vector<bool> can(n, false);

	while (rem.size() > 1) {
		int index = rem[rng() % rem.size()];
		cout << "? " << index + 1 << endl;

		int t;
		cin >> t;

		can.assign(n, false);
		for (int i = 0; i < n; ++i) {
			if (v[i] == t) {
				int R = (((index - i) % n) + n) % n;
				can[R] = true;
			}
		}

		vector<int> trem;
		for (auto x : rem) if (can[x]) trem.pb(x);

		rem = trem;
		vector<int> nv(n, 0);
		for (int i = 1; i < n; ++i) {
			nv[i-1] += v[i]/2;
			nv[(i+1)%n] += (v[i] - v[i]/2);
		}

		nv[1] += v[0];
		v = nv; 

	}

	cout << "! " << rem[0] + 1 << endl;

}