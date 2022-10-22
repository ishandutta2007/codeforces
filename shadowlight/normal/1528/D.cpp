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

void add(int& a, int b, int MOD = mod) {
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

const ll INF = 1e18 + 7;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector <vector<pair <int, int>>> guns(n);

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    guns[a].pb({b, c});
  }
  for (int i = 0; i < n; ++i) {
    sort(all(guns[i]));
  }

  vector <vector<int>> best(n);
  for (int i = 0; i < n; ++i) {
    best[i].pb(0);
    for (int j = guns[i].size() - 1; j > 0; --j) {
      int now = best[i].back();
      int pos = guns[i][now].x, sec = guns[i][now].y;

      int npos = guns[i][j].x, nsec = guns[i][j].y;
      int delta = (pos - npos + n) % n;
      if (nsec + delta < sec) {
        best[i].back() = j;
      }
    }
    for (int k = 1; k < (int) guns[i].size(); ++k) {
      int j = best[i].back();
      int now = k;
      int pos = guns[i][now].x, sec = guns[i][now].y;

      int npos = guns[i][j].x, nsec = guns[i][j].y;
      int delta = (pos - npos + n) % n;

      if (nsec + delta < sec) {
        best[i].pb(j);
      } else {
        best[i].pb(k);
      }
    }
  }


  for (int s = 0; s < n; ++s) {
    vector <ll> res(n, INF);
    res[s] = 0;
    vector <bool> used(n, false);

    for (int it = 0; it < n; ++it) {
      int v = -1;
      for (int u = 0; u < n; ++u) {
        if (!used[u] && (v == -1 || res[u] < res[v])) {
          v = u;
        }
      }
      used[v] = true;
      int rot = res[v] % n;

      int nxt = 0;
      for (int u = 0; u < (int) guns[v].size(); ++u) {
        if (rot + guns[v][u].x >= n) {
          nxt = u;
          break;
        }
      }

      for (int u = 0; u < n; ++u) {
        int kekw = rot + guns[v][nxt].x;
        if (kekw >= n) {
          kekw -= n;
        }
        if (u == kekw) {
          nxt += 1;
          if (nxt == guns[v].size()) {
            nxt = 0;
          }
        }
        int was = nxt - 1;
        if (was == -1) {
          was = guns[v].size() - 1;
        }
        int fire = best[v][was];

        int pos = (guns[v][fire].x + rot), sec = guns[v][fire].y;
        if (pos >= n) {
          pos -= n;
        }
        int delta = (u - pos);
        if (delta < 0) {
          delta += n;
        }
        res[u] = min(res[u], res[v] + delta + sec);
      }
    }

    for (int t = 0; t < n; ++t) {
      cout << res[t] << " ";
    }
    cout << "\n";
  }

}