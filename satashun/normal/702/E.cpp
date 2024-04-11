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
ll k;
int A[100010];
int w[100010];
ll sm[40][100010];
int mn[40][100010];
int to[40][100010];
ll rs[100010];
int rm[100010];
int cur[100010];

int main() {
    cin >> n >> k;

    rep(i, n) {
	cin >> A[i];
	to[0][i] = A[i];
    }

    rep(i, n) {
	cin >> w[i];
	sm[0][i] = mn[0][i] = w[i];
    }

    rep(i, 39) {
	rep(j, n) {
	    to[i + 1][j] = to[i][to[i][j]];
	    mn[i + 1][j] = min(mn[i][j], mn[i][to[i][j]]);
	    sm[i + 1][j] = sm[i][j] + sm[i][to[i][j]];
	}
    }

    rep(i, n) {
	cur[i] = i;
	rm[i] = INT_MAX;
    }

    rep(i, 40) {
	if ((k >> i) & 1) {
	    rep(j, n) {
		rm[j] = min(rm[j], mn[i][cur[j]]);
		rs[j] += sm[i][cur[j]];
		cur[j] = to[i][cur[j]];
	    }
	}
    }

    rep(i, n) {
	cout << rs[i] << " " << rm[i] << endl;
    }

    return 0;
}