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
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    vector<lint> cnt(30);
    REP(k, 30) REP(i, n) if(a[i]>>k&1) cnt[k]++;
    bool flg = false;
    IREP(k, 30) if(cnt[k]%2 != 0) {
      if(cnt[k]%4 == 1) {
        cout << "WIN" << "\n";
      } else {
        if((n-cnt[k])%2 != 0) {
          cout << "WIN" << "\n";
        } else {
          cout << "LOSE" << "\n";
        }
      }
      flg = true;
      break;
    }
    if(!flg) {
      cout << "DRAW" << "\n";
    }
  }
}