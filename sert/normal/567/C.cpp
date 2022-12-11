#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const ll N = 1e6 + 34;

ll n, k, ans;
map <ll, ll> p, s;
ll a[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	s[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
    	s[a[i]]--;
    	if (a[i] % k == 0) {
    		ans += p[a[i] / k] * s[a[i] * k];
    	}
    	p[a[i]]++;
    }
    cout << ans;
}