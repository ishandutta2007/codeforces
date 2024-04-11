#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const ll N = 1e6 + 34;

ll t, s, q, ans = 1, p = 0;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> t >> s >> q;
    for (int i = 0; true; i++) {
    	if (i % q)
    		s++;
    	if (t == s) {
    		cout << ans;
    		return 0;
    	}
    	if (p == s) {
    		p = 1;
    		ans++;
    	} else p++;
    }
}