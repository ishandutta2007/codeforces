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
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  REP(i, n) a[i]--;
  vector<int> cnt(100);
  vector<vector<int>> m(100, vector<int>(100));
  REP(i, n) {
    cnt[a[i]]++;
    int mx = 0;
    int idx = -1;
    REP(j, 100) {
      if(cnt[j] > mx) {
        mx = cnt[j];
        idx = j;
      }
    }
    REP(j, 100) chmax(m[idx][j], cnt[idx]-cnt[j]);
    REP(j, 100) if(cnt[a[i]] >= cnt[j]) chmax(m[a[i]][j], cnt[a[i]]-cnt[j]);
    REP(j, 100) if(cnt[a[i]] <= cnt[j]) chmax(m[j][a[i]], cnt[j]-cnt[a[i]]);
  }
  cnt = vector<int>(100);
  vector<vector<vector<int>>> mp(100, vector<vector<int>>(100, vector<int>()));
  REP(i, 100) REP(j, 100) {
    mp[i][j].push_back(0);
    REP(k, m[i][j]) mp[i][j].push_back(-1);
  }
  int ans = 0;
  REP(i, n) {
    cnt[a[i]]++;
    int mx = 0;
    int idx = -1;
    REP(j, 100) {
      if(cnt[j] > mx) {
        mx = cnt[j];
        idx = j;
      } 
    }
    REP(j, 100) if(idx != j && mp[idx][j][cnt[idx]-cnt[j]] != -1) chmax(ans, i+1-mp[idx][j][cnt[idx]-cnt[j]]);
    REP(j, 100) if(cnt[a[i]] >= cnt[j] && mp[a[i]][j][cnt[a[i]]-cnt[j]] == -1) mp[a[i]][j][cnt[a[i]]-cnt[j]] = i+1;
    REP(j, 100) if(cnt[a[i]] <= cnt[j] && mp[j][a[i]][cnt[j]-cnt[a[i]]] == -1) mp[j][a[i]][cnt[j]-cnt[a[i]]] = i+1;
  }
  cout << ans << endl;
}