#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while (t --) {
    	int n, k1, k2;
    	cin >> n >> k1 >> k2;

    	int w, b;
    	cin >> w >> b;

    	int cw = min(k1, k2) + (max(k1, k2) - min(k1, k2)) / 2;
    	k1 = n - k1, k2 = n - k2;
    	int cb = min(k1, k2) + (max(k1, k2) - min(k1, k2)) / 2;

    	cout << ((cw >= w && cb >= b) ? "YES" : "NO") << endl;
    }	
}