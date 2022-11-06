#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
vector<string> s;
vector<vector<int>> group;
int n;
int m;
void solve(int i, int j, int gr) {
  group[i][j] = gr;
  if(i != n-1 && s[i+1][j] == '#' && group[i+1][j] == -1) {
    solve(i+1, j, gr);
  }
  if(i != 0 && s[i-1][j] == '#' && group[i-1][j] == -1) {
    solve(i-1, j, gr);
  }
  if(j != m-1 && s[i][j+1] == '#' && group[i][j+1] == -1) {
    solve(i, j+1, gr);
  }
  if(j != 0 && s[i][j-1] == '#' && group[i][j-1] == -1) {
    solve(i, j-1, gr);
  }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    s = vector<string>(n);
    REP(i, n) cin >> s[i];
    bool vacant_row = false;
    bool vacant_col = false;
    REP(i, n) {
      bool flg = true;
      REP(j, m) {
        if(s[i][j] == '#') {
          flg = false;
          break;
        }
      }
      if(flg) vacant_row = true;
    }
    REP(j, m) {
      bool flg = true;
      REP(i, n) {
        if(s[i][j] == '#') {
          flg = false;
          break;
        }
      }
      if(flg) vacant_col = true;
    }
    if((vacant_row && !vacant_col) || (!vacant_row && vacant_col) ) {
      cout << -1 << endl;
      return 0;
    }

    group = vector<vector<int>>(n, vector<int>(m, -1));
    int gr = 0;
    REP(i, n) {
      REP(j, m) {
        if(s[i][j] == '#' && group[i][j] == -1) {
          solve(i, j, gr);
          gr++;
        }
      }
    }
    if(gr == 0) {
      cout << 0 << endl;
      return 0;
    }
    REP(i, n) {
      int mode = 0;
      REP(j, m) {
        if(s[i][j] == '#') {
          if(mode == 0) {
            mode++;
          } else if(mode == 2) {
            cout << -1 << endl;
            return 0;
          }
        } else {
          if(j != 0 && mode == 1) {
            mode++;
          }
        }
      }
    }
    REP(j, m) {
      int mode = 0;
      REP(i, n) {
        if(s[i][j] == '#') {
          if(mode == 0) {
            mode++;
          } else if(mode == 2) {
            cout << -1 << endl;
            return 0;
          }
        } else {
          if(i != 0 && mode == 1) {
            mode++;
          }
        }
      }
    }

    cout << gr << endl;

}