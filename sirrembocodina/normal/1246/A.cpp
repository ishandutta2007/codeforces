#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, p;
    cin >> n >> p;
    for (int ans = 1; ans <= 1000 && ans * (p + 1) <= n; ++ans) {
    	if (__builtin_popcount(n - ans * p) <= ans) {
    		cout << ans << endl;
    		return 0;
    	}
    }
    cout << -1 << endl;
}