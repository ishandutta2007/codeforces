#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mp make_pair

vector<int> spots;


int n, k;
ll A, B;

pair<ll, int> go(int lo, int hi, int as, int ae) {
	// cout << lo << " " << hi << " " << as << " " << ae << endl;

	while (ae >= 0 && spots[ae] > hi) ae--;
	while (as < spots.size() && spots[as] < lo) as++;

	if (as > ae) {
		return mp(A, ae);
	}

	int mid = (lo + hi)/2;
	ll o1 = B * (ae-as+1) * (hi - lo + 1);

	if (lo == hi) return mp(o1, ae);
	pair<ll, int> tmp = go(lo, mid, as, ae);
	ll o2 = tmp.first + 
		go(mid+1, hi, tmp.second+1, ae).first;
	return mp(min(o1, o2), ae);

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> A >> B;
	int cur;
	for (int i = 0; i < k; i++) {
		cin >> cur;
		spots.push_back(cur);
	}

	sort(spots.begin(), spots.end());

	int nc = 1;
	for (int i = 1; i <= n; i++) nc *= 2;

	// cout <<"HERE" << endl;

	cout << go(1, nc, 0, spots.size()-1).first << endl;
}