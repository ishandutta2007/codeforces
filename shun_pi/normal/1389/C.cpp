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
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    vector<int> cnt(10);
    REP(i, s.size()) cnt[s[i]-'0']++;
    int ans = 0;
    REP(i, 10) ans = max(ans, cnt[i]);
    REP(i, 10) {
      REP(j, 10) {
        if(i == j) continue;
        char c1 = '0' + i;
        char c2 = '0' + j;
        bool mode = false;
        int cnt = 0;
        REP(i, s.size()) {
          if(!mode && s[i] == c1) {
            mode = true;
          } else if(mode && s[i] == c2) {
            cnt += 2;
            mode = false;
          }
        }
        ans = max(ans, cnt);
      }
    }
    cout << s.size()-ans << "\n";
  }
}