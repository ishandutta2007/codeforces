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

typedef complex<double> P;
typedef pair<double, double> pdd;

const double pi = acos(-1.0);

inline double mf(double th)
{
    while (th < 0) th += 2 * pi;
    while (th > 2 * pi) th -= 2 * pi;
    return th;
}

int N;
ll x[100010], y[100010];

vector<pair<double, int>> vec;

bool pr(int i, int j) {
    ll dx1 = x[i] - x[0], dy1 = y[i] - y[0];
    ll dx2 = x[j] - x[0], dy2 = y[j] - y[0];
    return dx1 * dy2 - dx2 * dy1 == 0;
}

ll sq(int i)
{
    return (x[i]-x[0]) * (x[i]-x[0]) + (y[i]-y[0]) * (y[i]-y[0]);
}

ll dot(int i, int j)
{
    return (x[i]-x[0]) * (x[j]-x[0]) + (y[i]-y[0]) * (y[j]-y[0]);
}

vi id;

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> x[i] >> y[i];

    for (int i = 1; i < N; ++i) {
	P p(x[i]-x[0], y[i]-y[0]);
	vec.eb(mf(arg(p)), i);
    }
    sort(ALL(vec));

    rep(i, vec.size()) {
	bool f = 1;
	int j = vec[i].se;
	if (id.size() == 0) id.push_back(j);
	else {
	    if (pr(id.back(), j) && dot(id.back(), j) > 0) {
		if (sq(id.back()) > sq(j)) {
		    id.pop_back();
		    id.push_back(j);
		}
	    } else id.push_back(j);
	}
    }

    rep(i, id.size()) {
	int j = i + 1;
	if (j == id.size()) j = 0;

	int a = id[i], b = id[j];
	if (!pr(a, b)) {
	    cout << 1 << " " << a + 1 << " " << b + 1 << endl;
	    return 0;
	}
    }

    return 0;
}