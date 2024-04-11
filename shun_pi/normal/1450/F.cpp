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
    REP(i, n) a[i]--;
    vector<P> lr;
    int l = a[0];
    FOR(i, 1, n) {
      if(a[i] == a[i-1]) {
        lr.push_back(P(l, a[i-1]));
        l = a[i];
      }
    }
    lr.push_back(P(l, a[n-1]));
    vector<int> cnt(n);
    REP(i, lr.size()) if(lr[i].first == lr[i].second) cnt[lr[i].first]++;
    int mx = 0;
    int idx = 0;
    REP(i, n) if(cnt[i] > mx) {
      mx = cnt[i];
      idx = i;
    }
    //cout << mx << " " << idx << endl;
    mx--;
    REP(i, lr.size()) if(lr[i].first != idx && lr[i].second != idx) mx--;
    if(mx <= 0) {
      cout << lr.size()-1 << "\n";
      continue;
    }
    int cut = 0;
    FOR(i, 1, n) {
      if(a[i] != idx && a[i-1] != idx && a[i] != a[i-1]) cut++;
    }
    if(cut >= mx) cout << lr.size()-1+mx << "\n";
    else cout << -1 << "\n";
  }
}