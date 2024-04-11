#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100100;
const ll inf = 1LL << 55;

ll times(ll a, ll b) {
  if (a >= inf / b) return inf;
  else return a * b;
}

int _A[MAXN], _B[MAXN];

int N, M;

ll solve(int *ar, int len, ll sum) {
  ll ret = times(sum, len);
  ll curs = 0;
  for(int i = 0; i < len; ++i) {
    ll val = curs + times((len - i), sum);
    if (val < ret) ret = val;
    curs += ar[i];
  }
  return ret;
}

int main() {
  scanf("%d %d", &N, &M);
  ll smA = 0, smB = 0;
  for(int i = 0; i < N; ++i) {
    scanf("%d", _A + i);
    smA += _A[i];
  }

  for(int i = 0; i < M; ++i) {
    scanf("%d", _B + i);
    smB += _B[i];
  }

  sort(_A, _A + N);
  sort(_B, _B + M);

  ll ans1 = solve(_A, N, smB);
  ll ans2 = solve(_B, M, smA);

  if (ans1 < ans2) cout << ans1 << "\n";
  else cout << ans2 << "\n";
  return 0;
}