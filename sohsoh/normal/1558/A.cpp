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

const ll MAXN = 1e6 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		set<int> st;
		int a, b;
		cin >> a >> b;

		int n = a + b;
		for (int i = 0; i <= (n + 1) / 2; i++) {
			int w = a - i;
			int b = (n + 1) / 2 - i;
			if (w >= 0 && w <= n / 2) {
				b += w;
				st.insert(b);	
			}
		}

		for (int i = 0; i <= n / 2; i++) {
			int w = a - i;
			int b = n / 2 - i;
			if (w >= 0 && w <= (n + 1) / 2) {
				b += w;
				st.insert(b);
			}	
		}

		cout << st.size() << endl;
		for (int e : st) cout << e << sep;
		cout << endl;
	}
	return 0;
}