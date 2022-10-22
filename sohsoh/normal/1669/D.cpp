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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int cntr = 0, cntb = 0, n;
		string s;
		cin >> n >> s;
	
		bool flag = true;
		for (int i = 0; i < n; i++) {
			char c = s[i];
			cntr += (c == 'R');
			cntb += (c == 'B');

			if (c == 'W' || i == n - 1) {
				if (cntr || cntb) 
					flag &= (cntr > 0 && cntb > 0);
				cntr = cntb = 0;
			}
		}


		cout << (flag ? "YES" : "NO") << endl;	
			
	}
	return 0;
}