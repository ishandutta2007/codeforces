/*_______  ________  ___   ___  ________     
 /  ___  \|\   __  \|\  \ |\  \|\   __  \    
/__/|_/  /\ \  \|\  \ \  \\_\  \ \  \|\  \   
|__|//  / /\ \  \\\  \ \______  \ \   __  \  
    /  /_/__\ \  \\\  \|_____|\  \ \  \|\  \ 
   |\________\ \_______\     \ \__\ \_______\
    \|_______|\|_______|      \|__|\|_______|
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, m, cnt[MAXN];

inline bool check(int x) {
	ll delta = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] <= x) delta += (x - cnt[i]) / 2;
		else delta -= (cnt[i] - x);
	}

	return delta >= 0;
}

inline void solve() {
	for (int i = 0; i < m + 10; i++) cnt[i] = 0;
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	int l = 0, r = MAXN;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}