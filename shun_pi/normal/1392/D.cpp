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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    lint n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<lint, char>> len;
    char now = ' ';
    lint cnt = 0;
    REP(i, n) {
      if(s[i] != now) {
        if(cnt > 0) len.push_back(make_pair(cnt, now));
        now = s[i];
        cnt = 0;
      }
      cnt++;
    }
    if(cnt > 0) len.push_back(make_pair(cnt, now));
    lint ans = 0;
    if(len.size() > 1 && len[0].second == len[len.size()-1].second) {
      lint tmp = len[0].first + len[len.size()-1].first;
      len[len.size()-1] = make_pair(0, ' ');
      len[0] = make_pair(tmp, ' ');
    } else if(len.size() == 1) {
      ans++;
      len[0].first--;
    }
    REP(i, len.size()) {
      ans += len[i].first / 3;
    }
    cout << ans << "\n";
  }
}