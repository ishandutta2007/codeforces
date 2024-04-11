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

ll n, m;

int main() {
	cin >> n >> m;
	ll c = 1;

	rep(i, n) {
		c *= 2;
		if (m < c) {
			cout << m << endl;
			return 0;
		}
	}

	cout << m % c << endl;

	return 0;
}