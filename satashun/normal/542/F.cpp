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

int N, T;
int dp[110][1010];
vi vq[110];

int calc(int dep, int num)
{
    if (dep == T || num == 0) return 0;
    if (dp[dep][num] != -1) return dp[dep][num];

    int ret = 0;
    int s = 0;

    for (int i = 0; i <= vq[T - dep].size(); ++i) {
	if (i > num) break;
	ret = max(ret, s + calc(dep + 1, min((num - i) * 2, 1000)));
	if (i < vq[T - dep].size()) s += vq[T - dep][i];
    }

    return dp[dep][num] = ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> N >> T;

    rep(i, N) {
	int x, y;
	cin >> x >> y;
	vq[x].pb(y);
    }

    for (int i = 1; i <= T; ++i) {
	sort(ALL(vq[i]));
	reverse(ALL(vq[i]));
    }

    cout << calc(0, 1) << endl;

    return 0;
}