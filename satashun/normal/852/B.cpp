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

const ll MOD = 1000000007;

int N, L, M;
int st[1000010], gl[1000010], ct[1000010];
ll num[110];
ll dp[110], res[110], nx[110];
ll ans[110];

int main() {
	scanf("%d %d %d", &N, &L, &M);
	rep(i, N) {
		scanf("%d", &gl[i]);
		++ans[gl[i]];
	}
	rep(i, N) {
		scanf("%d", &ct[i]);
		++num[ct[i]];
	}
	rep(i, N) scanf("%d", &gl[i]);

	int k = L - 2;
	dp[0] = 1;
	rep(i, M) res[i] = num[i]; 

	while (k > 0) {
		if (k & 1) {
			memset(nx, 0, sizeof(nx));
			rep(i, M) {
				rep(j, M) {
					(nx[(i+j)%M] += dp[i] * res[j]) %= MOD;
				}
			}
			rep(i, M) dp[i] = nx[i];
		}
		memset(nx, 0, sizeof(nx));
		rep(i, M) {
			rep(j, M) {
				(nx[(i+j)%M] += res[i] * res[j]) %= MOD;
			}
		}
		rep(i, M) res[i] = nx[i];		
		k /= 2;
	}

	memset(nx, 0, sizeof(nx));
	rep(i, M) {
		rep(j, M) {
			(nx[(i+j)%M] += ans[i] * dp[j]) %= MOD;
		}
	}
	rep(i, M) ans[i] = nx[i];

	memset(nx, 0, sizeof(nx));

	ll ret = 0;

	rep(i, N) {
		int mm = (M + M - gl[i] - ct[i]) % M;
		ret = (ret + ans[mm]) % MOD;
	}

	cout << ret << endl;

	return 0;
}