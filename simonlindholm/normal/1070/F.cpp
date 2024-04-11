#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	string s;
	ll tot = 0;
	int totc = 0;
	vector<ll> as, bs, cs;
	rep(i,0,N) {
		int a;
		cin >> s >> a;
		if (s == "11") tot += a, totc++;
		else if (s == "10") as.push_back(a);
		else if (s == "01") bs.push_back(a);
		else cs.push_back(a);
	}
	sort(all(as));
	sort(all(bs));
	reverse(all(as));
	reverse(all(bs));
	if (sz(as) > sz(bs)) swap(as, bs);
	rep(i,0,sz(as)) {
		tot += as[i];
		tot += bs[i];
	}

	rep(i,sz(as),sz(bs)) cs.push_back(bs[i]);
	sort(all(cs));
	reverse(all(cs));
	rep(i,0,min(totc, sz(cs))) {
		tot += cs[i];
	}

	cout << tot << endl;
}