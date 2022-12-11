#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

pair<int, int> lst;
vector<pair<int, int>> vb, vw;
void init() {
	if (D) {
		vb.clear();
		vw.clear();
	}
}

void putPoint(int x, int y) {
	if (D) {
		lst = make_pair(x, y);
	} else {
		cout << x << " " << y << endl;
	}
}

string getColor(int x, int y) {
	putPoint(x, y);
	if (D) {
		string s = (rand() % 2 ? "black" : "white");
		if (s == "black") vb.push_back(lst);
		else vw.push_back(lst);
		return s;
	} else {
		string s;
		cin >> s;
		return s;
	}
}

ll sign(ll x) {
	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}

bool isOk(int x1, int y1, int x2, int y2) {
	if (D) {
		ll a = y1 - y2;
		ll b = x2 - x1;
		ll c = -a * x1 - b * y1;
		vector<int> sb, sw;
		for (auto q: vb) sb.push_back(sign(a * q.first + b * q.second + c));
		for (auto q: vw) sw.push_back(sign(a * q.first + b * q.second + c));
		sort(sb.begin(), sb.end());
		sort(sw.begin(), sw.end());
		if (!sb.empty() && sb.back() != sb[0]) return false;
		if (!sw.empty() && sw.back() != sw[0]) return false;
		if (!sb.empty() && !sw.empty() && sb[0] == sw[0]) return false;
		cout << "Ok!\n";
		return true;
	} else {
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		return true;
	}
}

void solve() {	
	int n;
	int l = 0;
	int r = (1 << 29);
	if (D) n = 1;
	else cin >> n;

	n--;
	string s0 = getColor(0, 34);

	while (n--) {
		int m = (l + r) / 2;
		string s = getColor(m, 34);
		if (s == s0) l = m;
		else r = m;

		//cout << m << " " << s << "\n";
	}

	if (!isOk(l, 31, r, 41)) {
		cout << "fail\n";
		exit(11);
	}
}

int main() {
	srand(3431);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 34;
	while (tst--) {
		init();
		solve();
	}
#else
	while (tst--) solve();
#endif
}