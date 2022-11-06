#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
    vector<int> ca(n);
    REP(i, n) cin >> ca[i];
    REP(i, n) ca[i]--;
    vector<int> cb(n);
    REP(i, n) cin >> cb[ca[i]];
    REP(i, n) cb[i]--;
    deque<int> que;
    REP(i, n) que.push_back(i);
    vector<int> cycles;
    vector<bool> vst(n);
    REP(i, n) {
      if(!vst[i]) {
        vst[i] = true;
        int c = cb[i];
        int cnt = 1;
        while(c != i) {
          vst[c] = true;
          c = cb[c];
          cnt++;
        }
        if(cnt%2 != 0) cnt--;
        cycles.push_back(cnt);
      }
    }
    lint ans = 0;
    for(int x : cycles) {
      vector<int> co;
      REP(i, x) {
        if(i%2 == 0) {
          co.push_back(que.front());
          que.pop_front();
        } else {
          co.push_back(que.back());
          que.pop_back();
        }
      }
      REP(i, co.size()) ans += abs(co[i] - co[(i+1)%x]);
    }
    cout << ans << "\n";
  }
}