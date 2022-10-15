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

int main() {
    ios_base::sync_with_stdio(0);
    srand(time(0));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n;
    set<int> h, v;
    for (int i = 1; i <= n * n; ++i) {
    	int a, b;
    	cin >> a >> b;
    	if (!h.count(a) && !v.count(b)) {
    		h.insert(a);
    		v.insert(b);
    		cout << i << ' ';
    	}
    }

    return 0;
}