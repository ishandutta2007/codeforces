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

double dp[110][100010];
double ac[110][100010];

double get(int i, int l, int r)
{
    if (l > r) return 0.0;
    double res = 0.0;
    if (r >= 0) res += ac[i][r];
    if (l >= 1) res -= ac[i][l - 1];
    return res;
}

int n, m;
int x[110], s;

int main() {
    cin >> n >> m;

    rep(i, n) {
	cin >> x[i];
	s += x[i];
    }

    if (m == 1) {
	puts("1");
	return 0;
    }

    dp[0][0] = 1.0;

    int cs = 0;

    rep(i, n) {
	cs += m;

	double t = 0;

	for (int j = 0; j <= cs; ++j) {
	    ac[i][j] = t + dp[i][j];
	    t += dp[i][j];
	}

	for (int j = 1; j <= cs; ++j) {
	    dp[i + 1][j] = get(i, j - x[i] + 1, j - 1);
	    dp[i + 1][j] += get(i, j - m, j - x[i] - 1);
	    dp[i + 1][j] /= (m - 1);
	}
    }

    double ret = 0.0;
    rep(i, s) ret += dp[n][i];

    printf("%.10f\n", 1.0 + ret * (m - 1));

    return 0;
}