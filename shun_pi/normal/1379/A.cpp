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
      int n;
      cin >> n;
      string s;
      cin >> s;
      string aba = "abacaba";
      bool flg = false;
      REP(i, n-6) {
          int cnt = 0;
          REP(j, 7) if(s[i+j] == aba[j] || s[i+j] == '?') cnt++;
          if(cnt == 7) {
            string ans = "";
            REP(j, n) {
                if(j >= i && j <= i+6) ans += aba[j-i];
                else if(s[j] == '?') ans += 'd';
                else ans += s[j];
            }
            int cnt2 = 0;
            REP(j, n-6) {
                int cnt3 = 0;
                REP(k, 7) if(ans[j+k] == aba[k]) cnt3++;
                if(cnt3 == 7) cnt2++;
            }
            if(cnt2 == 1) {
                cout << "Yes" << "\n";
                cout << ans << "\n";
                flg = true;
            }
            if(flg) break;
          }
      }
      if(!flg) cout << "No" << "\n";
  }
}