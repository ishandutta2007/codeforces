#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> pii;
const int MOD = 998244353;
typedef long long ll;
const int MAXN = 1001000;
int ar[MAXN];
int first[MAXN];
int last[MAXN];
set<int> taken;
vector<int> locs[MAXN];

int n, m;

const int MAXM = 2222;
int coordinates[MAXM];
int rev[MAXN];
void get_coords() {
  coordinates[0] = 0;
  coordinates[1] = m;
  for(int i = 1; i <= n; ++i) {
    coordinates[i * 2] = first[i];
    coordinates[i * 2 + 1] = last[i] + 1;
  }
  for(int i = 0; i < 2 * n + 2; ++i) {
    rev[coordinates[i]] = i;
  }
}

ll DP[MAXM][MAXM];
int depth;
ll getmid(int i);
ll getdp(int _start, int _end) {
  int start = coordinates[_start];
  int end = coordinates[_end];
  // printf("getdp %d %d (%d %d)\n", _start, _end, start, end);
  if (start == end) return 1;
  ll &res = DP[_start][_end];
  if (res) return res - 1;
  ++depth;
  int cur = -1;
  for(int i = 1; i <= n; ++i) {
    if (first[i] >= start && last[i] < end) {
      cur = i;
      break;
    }
  }
  if (cur == -1) {
    res = 0;
  } else {
    // printf("(%d) %d %d: %d\n", depth, start, end, cur);
    ll left = 0;
    ll mid = getmid(cur);
    ll right = 0;
    for(int i = 1; i <= n; ++i) {
      if (first[i] >= start && last[i] < end) {
        if (first[i] <= first[cur]) {
          // printf("(%d) %d Branch L\n", i, depth);
          left += getdp(_start, i * 2) * getdp(i * 2, cur * 2) % MOD;
          left %= MOD;
        }
        if (last[i] >= last[cur]) {
          // printf("(%d) %d Branch R\n", i, depth);
          right += getdp(cur * 2 + 1, i * 2 + 1) * getdp(i * 2 + 1, _end) % MOD;
          right %= MOD;
        }
      }
    }
    res = left * mid % MOD * right % MOD;
  }

  --depth;
  return res++;
}

ll mids[MAXM];

ll getmid(int cur) {
  ll &mid = mids[cur];
  if (mid) return mid - 1;

  mid = 1;
  for (int i = 0; i + 1 < locs[cur].size(); ++i) {
    mid *= getdp(rev[locs[cur][i] + 1], rev[locs[cur][i + 1]]);
    mid %= MOD;
  }
  return mid++;
}

int main() {
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    first[i] = m;
  }
  for(int i = 0; i < m; ++i) {
    cin >> ar[i];
    first[ar[i]] = min(first[ar[i]], i);
    last[ar[i]] = max(last[ar[i]], i);
    locs[ar[i]].push_back(i);
  }

  taken.insert(-1);
  taken.insert(m);
  bool bad = false;
  for(int i = 1; i <= n; ++i) {
    int f = first[i], l = last[i];
    ll left, right;
    set<int>::iterator it = taken.upper_bound(f);
    if (*it < l) {
      bad = true;
    } else {
      right = *it - l;
    }
    --it;
    left = l - *it;
    for(int j = 0; j < locs[i].size(); ++j) {
      taken.insert(locs[i][j]);
    }
  }


  get_coords();
  ll ans = getdp(0, 1);
  cout << ans << "\n";
}