#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll ib, is, ic;
ll nb, ns, nc;
ll pb, ps, pc;
ll r;

bool check(ll u) {
	ll bn = ib*u - nb;
	ll sn = is*u - ns;
	ll cn = ic*u - nc;
	ll cost = 0;
	if (bn > 0) cost += bn*pb;
	if (sn > 0) cost += sn*ps;
	if (cn > 0) cost += cn*pc;
	if (cost <= r) return true;
	return false;
}

int main() {
	string line;
	cin >> line;
	ib = 0;
	is = 0;
	ic = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'B') ib++;
		else if (line[i] == 'S') is++;
		else ic++;
		
	}
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;
	ll low = 0;
	ll high = r + 200;
	while (low < high) {
		ll mid = (low+high+1)/2;
		if (check(mid)) {
			low = mid;
			if (!check(mid+1)) high = mid;
		}
		else {
			high = mid-1;
		}
	}
	cout << low << endl;
	cin >> ib;
}