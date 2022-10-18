#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007;

int main() {
	cin.sync_with_stdio(false);
	int N;
	string s;
	cin >> N >> s;
	vector<int> t(256);
	trav(x, s) {
		++t[x];
	}
	vector<int> v = {t['A'], t['T'], t['G'], t['C']};
	int ma = 0;
	rep(i,0,4) ma = max(ma, v[i]);
	int count = 0;
	rep(i,0,4) if (v[i] == ma) count++;
	ll res = 1;
	rep(i,0,N) res = res * count % mod;
	cout << res << endl;
}