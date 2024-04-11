#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll n, sum, ans, a[N];
char t[N];
bool u[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> t[i] >> a[i];
    	if (!u[a[i]] && t[i] == '-') {
    		u[a[i]] = true;
    		sum++;
    	}
    	if (t[i] == '+')
    		u[a[i]] = true;
    }
    ans = sum;
    for (int i = 0; i < n; i++) {
    	if (t[i] == '-') {
    		sum--;
    	} else {
    		sum++;
    	}
    	ans = max(ans, sum);
    }
    cout << ans;
}