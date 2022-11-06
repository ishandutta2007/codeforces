#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr lint B1 = 1532834020;
constexpr lint M1 = 2147482409;
constexpr lint B2 = 1388622299;
constexpr lint M2 = 2147478017;
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
template<class T>void chmax(T &a, const T &b) { if (a<b) a=b; }
template<class T>void chmin(T &a, const T &b) { if (b<a) a=b; }
void flip(int i, int j, vector<string> &s) {
  s[i][j] = (s[i][j] == '1') ? '0' : '1';
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    vector<vector<int>> ans(n*m, vector<int>(6));
    int ptr = 0;
    REP(i, n-2) REP(j, m) {
      if(s[i][j] == '1') {
        if(j != m-1) {
          ans[ptr] = {i+1, j+1, i+2, j+1, i+2, j+2}; 
          flip(i, j, s);
          flip(i+1, j, s);
          flip(i+1, j+1, s);
        } else {
          ans[ptr] = {i+1, j+1, i+2, j+1, i+2, j};  
          flip(i, j, s);
          flip(i+1, j, s);
          flip(i+1, j-1, s);
        }
        ptr++;
      }
    }
    REP(j, m-2) {
      if(s[n-2][j] == '1' && s[n-1][j] == '1') {
        ans[ptr] = {n-1, j+1, n, j+1, n-1, j+2};
        flip(n-2, j, s);
        flip(n-1, j, s);
        flip(n-2, j+1, s);
        ptr++;
      } else if(s[n-2][j] == '1' && s[n-1][j] == '0') {
        ans[ptr] = {n-1, j+1, n-1, j+2, n, j+2};
        flip(n-2, j, s);
        flip(n-2, j+1, s);
        flip(n-1, j+1, s);
        ptr++;
      } else if(s[n-2][j] == '0' && s[n-1][j] == '1') {
        ans[ptr] = {n, j+1, n-1, j+2, n, j+2};
        flip(n-1, j, s);
        flip(n-2, j+1, s);
        flip(n-1, j+1, s);
        ptr++;
      }
    }
    int cnt = 0;
    FOR(i, n-2, n) FOR(j, m-2, m) if(s[i][j] == '1') cnt++;
    if(cnt == 4) {
      ans[ptr] = {n-1, m, n, m-1, n, m};
      flip(n-2, m-1, s);
      flip(n-1, m-2, s);
      flip(n-1, m-1, s);
      cnt = 1;
      ptr++;
    }
    if(cnt == 1) {
      if(s[n-2][m-2] == '1') {
        ans[ptr] = {n-1, m-1, n, m-1, n, m};
        flip(n-2, m-2, s);
        flip(n-1, m-2, s);
        flip(n-1, m-1, s);
        cnt = 2;
        ptr++;
      } else {
        ans[ptr] = {n-1, m, n, m-1, n, m};
        flip(n-2, m-1, s);
        flip(n-1, m-2, s);
        flip(n-1, m-1, s);
        cnt = 2;
        ptr++;
      }
    }
    if(cnt == 2) {
      if(s[n-2][m-2] == '0' && s[n-1][m-1] == '1') {
        ans[ptr] = {n-1, m-1, n, m-1, n-1, m};
        flip(n-2, m-2, s);
        flip(n-1, m-2, s);
        flip(n-2, m-1, s);
        ptr++;
      } else if(s[n-2][m-2] == '0' && s[n-1][m-1] == '0') {
        ans[ptr] = {n-1, m-1, n, m-1, n, m};
        flip(n-2, m-2, s);
        flip(n-1, m-2, s);
        flip(n-1, m-1, s);
        ptr++;
      } else {
        ans[ptr] = {n-1, m, n, m-1, n, m};
        flip(n-2, m-1, s);
        flip(n-1, m-2, s);
        flip(n-1, m-1, s);
        ptr++;
      }
      cnt = 3;
    }
    if(cnt == 3) {
      if(s[n-2][m-2] == '0') {
        ans[ptr] = {n-1, m, n, m-1, n, m};
        flip(n-2, m-1, s);
        flip(n-1, m-2, s);
        flip(n-1, m-1, s);
      } else if(s[n-2][m-1] == '0') {
        ans[ptr] = {n-1, m-1, n, m-1, n, m};
        flip(n-2, m-2, s);
        flip(n-1, m-2, s);
        flip(n-1, m-1, s);
      } else if(s[n-1][m-2] == '0') {
        ans[ptr] = {n-1, m-1, n-1, m, n, m};
        flip(n-2, m-2, s);
        flip(n-2, m-1, s);
        flip(n-1, m-1, s);
      } else {
        ans[ptr] = {n-1, m-1, n, m-1, n-1, m};
        flip(n-2, m-2, s);
        flip(n-1, m-2, s);
        flip(n-2, m-1, s);
      }
    }
    
    cnt = 0;
    REP(i, n*m) {
      if(ans[i][0] == 0) break;
      cnt++;
    }
    cout << cnt << "\n";
    REP(i, cnt) {
      REP(j, 6) cout << ans[i][j] << (j!=6-1 ? " " : "");
      cout << "\n";
    }

    //REP(i, n) cout << s[i] << "\n";
  }
}