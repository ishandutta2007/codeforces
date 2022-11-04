#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
 
template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
 
void run();
 
signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

int ask(int shift) {
	cout << "? ";
	for (int i = 1; i <= 100; ++i) {
		cout << (i << shift) << " ";
	}
	cout << endl;
	int v;
	cin >> v;
	return v;
}

void run() {
	int ans = (ask(0) >> 7) << 7;
	int v = ask(7);
	v -= ((v >> 7) << 7);
	ans += v;
	cout << "! " << ans << endl;
}