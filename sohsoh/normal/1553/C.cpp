// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e3 + 10;

string s;

inline int solve() {
	cin >> s;

	int ans = 10, sc[2] = {0, 0};
	
	for (int i = 0; i < 10; i++) {
		if (s[i] == '1') sc[i & 1]++;
		else if (s[i] == '?' && (i & 1) == 0) sc[0]++; 
		if ((10 - i) / 2 + sc[1] < sc[0]) ans = min(ans, i + 1); 
	}
	
	sc[0] = sc[1] = 0;	
	for (int i = 0; i < 10; i++) {
		if (s[i] == '1') sc[i & 1]++;
		else if (s[i] == '?' && (i & 1)) sc[1]++; 
		if ((10 - i - 1) / 2 + sc[0] < sc[1]) ans = min(ans, i + 1); 
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		solve();
	}
	return 0;
}