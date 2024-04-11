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
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<int> lis(n);
    lis[0] = 1;
    cout << 1 << "\n";
    FOR(i, 1, n) {
      if(a[i] == 1) {
        REP(j, n) if(lis[j] == 0) {
          lis[j]++;
          break;
        }
      }
      else {
        IREP(j, n) if(lis[j] == a[i]-1) {
          lis[j]++;
          FOR(k, j+1, n) lis[k] = 0;
          break;
        }
      }
      REP(j, lis.size()) {
        if(j > 0 && lis[j] > 0) cout << ".";
        if(lis[j] > 0) cout << lis[j];
      }
      cout << "\n";
    }
  }
}