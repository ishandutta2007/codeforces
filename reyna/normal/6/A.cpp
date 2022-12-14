//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define end __

const int N = 0;

int read() { int x; cin >> x; return x; }

int a[4];

void end(string s) {
	cout << s;
	exit(0);	
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; ++i)
		cin >> a[i];
	sort(a, a + 4);
	if (a[1] + a[2] > a[3]) {
		end("TRIANGLE");
	}
	if (a[0] + a[1] > a[2]) {
		end("TRIANGLE");	
	}
	if (a[1] + a[2] == a[3]) {
		end("SEGMENT");	
	}
	if (a[0] + a[1] == a[2]) {
		end("SEGMENT");	
	}
	end("IMPOSSIBLE");
	
	
	
}