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

ll s, x;
bool u[60];
ll ret = 1;

int main() {
    cin >> s >> x;
    bool f = (s == x);

    rep(i, 60) {
	if ((x >> i) & 1) {
	    u[i] = 1;
	    s -= (1LL << i);
	    ret *= 2;
	}
    }

    rep(i, 60) {
	if (!u[i]) {
	    if (s & (1LL <<  (i + 1))) {
		s -= 1LL << (i + 1);
	    }
	}
    }

    if (s != 0) ret = 0;
    else if (f) ret -= 2;
    cout << ret << endl;

    return 0;
}