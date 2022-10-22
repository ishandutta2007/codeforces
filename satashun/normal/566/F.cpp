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
int cnt[1000010];
int dp[1000010];
int ret;

int main() {
    scanf("%d", &n);

    rep(i, n) {
	int x;
	scanf("%d", &x);
	++cnt[x];
    }

    for (int i = 1; i <= 1000000; ++i) {
	dp[i] += cnt[i];
	ret = max(ret, dp[i]);

	for (int j = i * 2; j <= 1000000; j += i) {
	    dp[j] = max(dp[j], dp[i]);
	}
    }

    printf("%d\n", ret);

    return 0;
}