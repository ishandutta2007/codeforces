#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e3;
int arr[MAXN];
bool used[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> arr[i];
    	used[i] = 0;
    }

    int cnt = 0;
    int ans = 0;
    while (cnt != n) {
    	for (int i = 0; i < n; ++i) {
    		if (cnt >= arr[i] && !used[i]) {
    			used[i] = 1;
    			++cnt;
    		}
    	}
    	if (cnt == n)
    		break;
    	++ans;
    	for (int i = n - 1; i >= 0; --i) {
    		if (cnt >= arr[i] && !used[i]) {
    			used[i] = 1;
    			++cnt;
    		}    		
    	}
    	if (cnt == n)
    		break;
    	++ans;
    }

    cout << ans << '\n';

    return 0;
}