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

typedef double R;

const R INF = 1e15;

R dp[2][200010];
int deq[200010];
int n, k;

R a[200010];
R b[200010];
R s[200010];
R t[200010];

R f(int j, int pos, int k)
{
    return -s[j] * b[pos + 1] + dp[k][j] + b[j] * s[j]; 
}

bool ng(int t1, int t2, int t3, int k)
{
    double a1 = -s[t1], b1 = dp[k][t1] + b[t1] * s[t1];
    double a2 = -s[t2], b2 = dp[k][t2] + b[t2] * s[t2];
    double a3 = -s[t3], b3 = dp[k][t3] + b[t3] * s[t3];
    return (a2 - a1) * (b3 - b2) >= (b2 - b1) * (a3 - a2);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;

    R sm = 0;

    rep(i, n) {
	cin >> t[i];
	sm += t[i];

	s[i + 1] = sm;
	a[i + 1] = a[i] + sm / t[i];
	b[i + 1] = b[i] + 1.0 / t[i];
    }

    rep(i, 2) for (int j = 0; j <= n; ++j) dp[i][j] = INF;
    dp[0][0] = 0;

    int c = 0, u = 1;

    for (int i = 1; i <= k; ++i) {
	int s = 0, t = 0;

	for (int j = 0; j <= n; ++j) dp[u][j] = INF;

	rep(j, n) {
	    while (s + 1 < t && ng(deq[t - 2], deq[t - 1], j, c)) --t;
	    deq[t++] = j;

	    while (s + 1 < t && f(deq[s], j, c) >= f(deq[s + 1], j, c)) ++s;
	    dp[u][j + 1] = f(deq[s], j, c);
	}

	swap(c, u);
    }

    cout << fixed << setprecision(7) << dp[c][n] + a[n] << endl;
    return 0;
}