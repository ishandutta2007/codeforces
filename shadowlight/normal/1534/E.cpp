#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int INF = 1e9 + 7;


int main(){
  int n, k;
  cin >> n >> k;

  vector <int> dp(n + 1, INF);
  vector <int> pr(n + 1, -1);


  dp[0] = 0;
  queue <int> q;
  q.push(0);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (int b = 0; b <= min(a, k); ++b) {
      int c = a - b + (k - b);
      if (c > n || (k - b) > n - a || dp[c] != INF) continue;
      dp[c] = dp[a] + 1;
      pr[c] = a;
      q.push(c);
    }
  }
  if (dp[n] == INF) {
    cout << "-1" << endl;
    return 0;
  }
  vector <int> counts;
  int now = n;
  while (now != 0) {
    counts.pb(now);
    now = pr[now];
  }
  reverse(all(counts));

  int res = 0;

  int a = 0;
  vector <bool> used(n, false);
  for (int c : counts) {
    for (int b = 0; b <= min(a, k); ++b) {
      if (c != a - b + (k - b)) continue;

      int bb = 0;
      int cc = 0;
      vector <int> tet;
      for (int i = 0; i < n; ++i) {
        if (used[i]) {
          if (bb < b) {
            used[i] = false;
            tet.pb(i);
            ++bb;
          }
        } else {
          if (cc < k - b) {
            used[i] = true;
            tet.pb(i);
            ++cc;
          }
        }
      }
      assert(bb == b && cc == k - b);
      cout << "? ";
      for (int x : tet) {
        cout << x + 1 << " ";
      }
      cout << endl;

      int y;
      cin >> y;
      res ^= y;

      break;
    }
    a = c;
  }
  cout << "! " << res << endl;
}