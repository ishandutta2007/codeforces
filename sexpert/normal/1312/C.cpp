#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;
    vector<int> cnt(100);
    for(int i = 0; i < 100; i++) {
        for(auto &x : v) {
            cnt[i] += (x % k);
            x /= k;
        }
    }
    for(int i = 0; i < 100; i++) {
        if(cnt[i] > 1) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
    cin >> t;
    while(t--)
        solve();
}