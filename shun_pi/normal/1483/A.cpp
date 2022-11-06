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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(m);
    vector<int> cnt(n);
    vector<int> solo(n);
    REP(i, m) {
      int k;
      cin >> k;
      f[i] = vector<int>(k);
      REP(j, k) {
        cin >> f[i][j];
        f[i][j]--;
        cnt[f[i][j]]++;
        if(k == 1) solo[f[i][j]]++;
      }
    }
    int ma = 0;
    int idx = -1;
    REP(i, n) if(cnt[i] > ma) {
      ma = cnt[i];
      idx = i;
    }
    int nonsolopick = m;
    if(ma > (m+1)/2) {
      if(solo[idx] > (m+1)/2) {
        cout << "NO" << "\n";
        continue;
      }
      nonsolopick = (m+1)/2 - solo[idx];
    }
    vector<int> ans(m);
    cnt = vector<int>(n);
    REP(i, m) {
      if(f[i].size() == 1 && f[i][0] == idx) {
        ans[i] = idx;
        cnt[idx]++;
      } else {
        bool has = false;
        int other = -1;
        REP(j, f[i].size()) if(f[i][j] == idx && cnt[f[i][j]] < (m+1)/2) {
          has = true;
        } else if(cnt[f[i][j]] < (m+1)/2) {
          other = f[i][j];
        }
        if(has && nonsolopick > 0) {
          ans[i] = idx;
          cnt[idx]++;
          nonsolopick--;
        } else {
          ans[i] = other;
          cnt[other]++;
        }
      }
    }
    cout << "YES" << "\n";
    REP(i, m) cout << ans[i]+1 << (i!=m-1 ? " " : "");
    cout << "\n";
  }
}