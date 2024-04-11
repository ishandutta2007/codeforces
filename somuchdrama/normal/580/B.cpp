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


const int MAXN = 1e5+1;
vector<pll> arr(MAXN);
ll sum[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    ll n, d;
    cin >> n >> d;
    --d;
    arr[0].ff = arr[0].ss = 0;
    for (int i = 1; i <= n; ++i)
    	cin >> arr[i].ff >> arr[i].ss;

    sort(arr.begin(), arr.begin() + n + 1);

    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	sum[i] = sum[i - 1] + arr[i].ss;
    }

    ll mx = 0;
    for (int i = 1; i <= n; ++i) {
    	ll nd = arr[i].ff + d;
    	int l = i - 1, r = n + 1;
    	while (r - l > 1) {
    		int m = (r + l) / 2;
    		if (arr[m].ff > nd) 
    			r = m;
    		else
    			l = m;
    	}
    	mx = max(mx, sum[l] - sum[i - 1]);
    }

    cout << mx << '\n';

    return 0;
}