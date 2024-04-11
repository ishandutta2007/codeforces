#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
string s;

int main() {
	cin >> n;
	if (n == 0) {
		cout << "a" << endl;
		return 0;
	}
	int now = 0;
	while (n > 0) {
		int m = 0;
		for (int i = 1; i * (i-1) / 2 <= n; ++i) {
			m = i;
		}
		n -= m * (m-1) / 2;
		rep(i, m) s.pb('a' + now);
		++now;
	}
	cout << s << endl;

	return 0;
}