#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    forn (q, t) {
    	int n;
    	cin >> n;
    	if (n == 1) {
    		cout << -1 << endl;
    	} else {
    		forn (i, n - 1) {
    			cout << '9';
    		}
    		cout << '4' << endl;
    	}
    }
}