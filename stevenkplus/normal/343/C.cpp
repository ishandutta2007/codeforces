#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN = 100100;
const ll MAXH = 20000000000LL;

int N, M;

ll H[MAXN];
ll P[MAXN];

bool reach (ll t, ll c, ll a, ll b) {
  if (abs(a-c) + b - a <= t) return true;
  if (abs(b-c) + b - a <= t) return true;
  return false;
}

bool works(ll time) {
  int cur = 0;
  for(int i = 0; i < N && cur < M; ++i) {
    ll start = P[cur];
    ll end = P[cur];
    while (cur < M && reach(time, H[i], start, end)) {
      ++cur;
      end = P[cur];
    }
  }
  return cur == M;
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> N >> M;
  for(int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  for(int i = 0; i < M; ++i) {
    cin >> P[i];
  }

  ll lo = 0;
  ll hi = MAXH;

  while (lo < hi) {
    ll mid = (lo + hi) / 2;
    if (works(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo << endl;
  return 0;
}