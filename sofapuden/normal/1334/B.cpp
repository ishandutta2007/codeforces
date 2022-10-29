#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< (fl == vec.size()-1?"\n":sep;)}
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve() {
	int n,x; cin >> n>>x;
	vector<ll> v;
	ll sum = 0;
	rep(i, 0, n) {
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(all(v));
	reverse(all(v));
	rep(i, 0, v.size()) {
		sum += v[i];
		if (sum / (i + 1) < x) {
			cout << i << endl;
			return;
		}
	}
	cout << v.size() << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
}