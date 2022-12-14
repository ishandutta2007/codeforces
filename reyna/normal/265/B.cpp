//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


const int N = 1e5 + 5;

int read() { int x; cin >> x; return x; }

int h[N];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int n = read(), res = n + n - 1, cur = 0;
	for (int i = 0; i < n; i++) {
		h[i] = read();
		if (i) {
			res += abs(h[i - 1] - h[i]);	
		} else res += h[i];
	}
	
	cout << res << endl;
	
	
	
}