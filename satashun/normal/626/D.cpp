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

const int B = 16000;
const int T = 5010;

int n;
int a[2010];
int num[11000];
double dp[4][6000];
double ret;

int main() {
	cin >> n;
	rep(i, n) cin >> a[i];

	rep(i, n) rep(j, n) if (i != j) {
		if (a[i] > a[j]) ++num[a[i] - a[j]];
	}

	dp[0][0] = 1.0;

	rep(i, 2) {
		for (int j = 0; j < 6000; ++j) {
			for (int k = 1; k + j < 6000; ++k) {
				dp[i+1][j+k] += dp[i][j] * num[k] * 2 / n / (n-1);
			}
		}
	}

	rep(j, 6000) {
		for (int k = j + 1; k < 11000; ++k) {
			ret += dp[2][j] * num[k] * 2 / n / (n-1); 
		}
	}

	printf("%.9f\n", ret);

	return 0;
}