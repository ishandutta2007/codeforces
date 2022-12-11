#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main() {
	cin.tie(0);
	int n, t; cin >> t;
	REP(it, t) {
		cin >> n;
		vector<int> a(n), cnt(n);
		REP(i, n) cin >> a[i], a[i] = i - a[i];
		int pos = 0, s = 0;
		REP(i, 2 * n) cnt[pos]++, pos = a[pos];
		REP(i, n) if(cnt[i] > 1) s++;
		cout << s << "\n";
		REP(i, n) if(cnt[i] > 1) cout << i + 1 << " ";
		cout << "\n";
	}
}