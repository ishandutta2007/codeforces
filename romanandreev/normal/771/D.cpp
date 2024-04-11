#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}
int dp[76][76][76][3];
const int inf = 1e6;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'V') {
      a[i] = 0;
    } else
    if (s[i] == 'K') {
      a[i] = 1;
    } else {
      a[i] = 2;
    }
  }
  vector<vector<int>> ls(3);
  for (int i = 0; i < n; i++) {
    ls[a[i]].pb(i);
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        for (int l = 0; l < 3; l++) {
          dp[i][j][k][l] = inf;
        }
      }
    }
  }
  dp[0][0][0][2] = 0;
  int ans = inf;
  for (int i = 0; i <= sz(ls[0]); i++) {
    for (int j = 0; j <= sz(ls[1]); j++) {
      for (int k = 0; k <= sz(ls[2]); k++) {
        for (int l = 0; l < 3; l++) if (dp[i][j][k][l] < inf) {
          if (i + j + k == n) {
            ans = min(ans, dp[i][j][k][l]);
          }
          vector<int> cur = {i, j, k};
          for (int t = 0; t < 3; t++) if (cur[t] + 1 <= sz(ls[t])) {
            if (t == 1 && l == 0) {
              continue;
            }
            int val = 0;
            for (int f = 0; f < 3; f++) if (f != t) {
              for (int w = 0; w < cur[f]; w++) {
                if (ls[f][w] > ls[t][cur[t]]) {
                  val++;
                }
              } 
            }
            if (dp[i + (t == 0)][j + (t == 1)][k + (t == 2)][t] > dp[i][j][k][l] + val) {
              dp[i + (t == 0)][j + (t == 1)][k + (t == 2)][t] = dp[i][j][k][l] + val;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  solve();
  return 0;
}