#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 110;
const int MAXM = 20;
const ll infl = 1LL << 61;

int K[MAXN];
int can[MAXN];
int cost[MAXN];
pii srt[MAXN]; // sorted by K
ll DP[2][1 << MAXM];

int N, M, B;

int target;
ll getdp(int _cur, int msk) {
  if (msk == target) {
    ll mon = K[_cur - 1];
    return mon * B;
  } else if (_cur >= N) {
    return infl;
  }

  ll &ret = DP[_cur][msk];
  if (ret) return ret - 1;
  int cur = srt[_cur].second;
  int nmsk = msk | can[cur];
  ll choice2 = getdp(_cur + 1, msk);
  ll choice1 = getdp(_cur + 1, nmsk) + cost[_cur];
  ret = min(choice1, choice2);
  return ret++;
}

int main() {
  scanf("%d %d %d", &N, &M, &B);

  for(int i = 0; i < N; ++i) {
    int m;
    scanf("%d %d %d", cost + i, K + i, &m);
    int &msk = can[i];
    for(int j = 0; j < m; ++j) {
      int nxt;
      scanf("%d", &nxt);
      --nxt;
      msk |= (1 << nxt);
    }
    srt[i] = pii(K[i], i);
  }

  sort(srt, srt + N);
  target = (1 << M) - 1;
  for(int i = N; i >= 0; --i) {
    int cur = srt[i].second;
    for(int j = 0; j < (1 << M); ++j) {
      ll &ret = DP[i & 1][j];
      if (j == target) {
        if (i > 0) ret = K[srt[i - 1].second] * ll(B);
      } else if (i == N) ret = infl;
      else {
        int nmsk = j | can[cur];
        ll choice1 = DP[(i + 1) & 1][j];
        ll choice2 = DP[(i + 1) & 1][nmsk] + cost[cur];
        ret = min(choice1, choice2);
      }
    }
  }

  ll ans = DP[0][0];
  if (ans == infl) ans = -1;

  cout << ans << "\n";
  return 0;
}