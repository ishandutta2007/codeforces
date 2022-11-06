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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int score = 0;
    int cnt = 0;
    int lsum = 0;
    int lsum2 = 0;
    vector<int> loses;
    bool flg = false;
    REP(i, n) {
      if(s[i] == 'L') {
        lsum2++;
        if(!flg) lsum++;
        else cnt++;
      } else {
        if(i > 0 && s[i-1] == 'W') score += 2;
        else score += 1;
        flg = true;
        if(cnt > 0) {
          loses.push_back(cnt);
          cnt = 0;
        }
      }
    }
    if(cnt > 0) lsum += cnt;
    sort(ALL(loses));
    REP(i, loses.size()) {
      while(k > 0 && loses[i] > 0) {
        if(loses[i] == 1) score += 3;
        else score += 2;
        k--;
        loses[i]--;
      }
    }
    score += min(k, lsum) * 2;
    if(score > 0 && lsum2 == n) score--;
    cout << score << "\n";
  }
}