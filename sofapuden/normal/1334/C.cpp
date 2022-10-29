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
	int n; cin >> n;
	const ll zero= 0;
	vector<pair<ll,ll>> vp(n);
	rep(i, 0, n) {
		cin >> vp[i].first >> vp[i].second;
	}
	ll sum = 0;
	rep(i, 1, vp.size()) {
		sum += max(zero, vp[i].first - vp[i - 1].second);
		vp[i].first = min(vp[i].first, vp[i - 1].second);
	}
	sum += max(zero, vp[0].first - vp[vp.size() - 1].second);
	vp[0].first = min(vp[0].first, vp[vp.size() - 1].second);
	sort(all(vp));
	sum += vp[0].first;
	cout << sum << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
}