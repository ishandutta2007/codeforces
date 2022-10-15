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

const int MAXN = 1e5;
int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
    	cin >> arr[i];

    int st = 0, mx = 1;
    for (int i = 0; i < n - 1; ++i) {
		st = 0;
		for (int j = i; j < n - 1 && (arr[j] <= arr[j + 1]); ++j) 
			++st;
		i += st;
		mx = max(mx, st + 1);
    }

    cout << mx << '\n';

    return 0;
}