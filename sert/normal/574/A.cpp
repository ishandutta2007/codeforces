#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll n, a[N], x, mx;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    while (true) {
    	mx = 1;
    	for (int i = 2; i < n; i++)
    		if (a[i] > a[mx])
    			mx = i;
    	if (a[0] > a[mx]) {
    		cout << x;
    		return 0;
    	}
    	a[0]++;
    	a[mx]--;
    	x++;
    }
}