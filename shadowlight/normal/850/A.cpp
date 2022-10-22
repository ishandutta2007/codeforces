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

int sc(vector<int> a, vector<int> b) {
	int sum = 0;
	for (int i = 0; i < a.size(); ++i) {
		sum += a[i] * b[i];
	}
	return sum;
}

vector<int> dec(vector<int> a, vector<int> b) {
	vector <int> c(5);
	for (int i = 0; i < a.size(); ++i) {
		c[i] = a[i] - b[i];
	}
	return c;
}

const db PI = acos(-1);
const db EPS = 1e-8;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n >= 57) {
		cout << "0\n";
		return 0;
	}

	vector <vector<int>> ps(n);

	for (int i = 0; i < n; ++i) {
		ps[i].resize(5);
		for (int j = 0; j < 5; ++j) {
			cin >> ps[i][j];
		}
	}

	vector <int> res;

	for (int i = 0; i < n; ++i) {
		bool bad = false;
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			for (int k = 0; k < n; ++k) {
				if (i == k || j == k) continue;
				auto a = dec(ps[j], ps[i]);
				auto b = dec(ps[k], ps[i]);
			
				db top = sc(a, b);
				db bot = sqrt(abs(sc(a, a))) * sqrt(abs(sc(b, b)));

				db ang = acos(top / bot);
				if (ang + EPS < PI / 2) {
					bad = true;
				}
			}
		}
		if (!bad) {
			res.pb(i);
		}
	}

	cout << res.size() << "\n";
	for (int x : res) {
		cout << x + 1 << " ";
	}
	cout << "\n";

}