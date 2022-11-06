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
    string A, B;
    cin >> A >> B;
    bool flg = false;
    REP(i, n) if(A[i] > B[i]) {
      flg = true;
      break;
    }
    if(flg) {
      cout << -1 << "\n";
      continue;
    }
    int ans = 0;
    REP(i, 20) {
      char minchar = 'z';
      REP(j, n) if(A[j] == ('a'+ i) && A[j] < B[j]) minchar = min(minchar, B[j]);
      if(minchar != 'z') {
        ans++;
        REP(j, n) if(A[j] == ('a'+i) && A[j] < B[j]) A[j] = minchar;
      }
    }
    cout << ans << "\n";
  }
}