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
struct Bunsuu {
  int g;
  lint p = 0, q = 1;
  Bunsuu(lint _p, lint _q): p(_p), q(_q) {};
  Bunsuu(): p(0), q(1) {};
  bool operator < (const Bunsuu &other) const { return p * other.q < q * other.p; };
  bool operator <= (const Bunsuu &other) const { return p * other.q <= q * other.p; };
  bool operator >= (const Bunsuu &other) const { return p * other.q >= q * other.p; };
  bool operator > (const Bunsuu &other) const { return p * other.q > q * other.p; };
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    lint n, m;
    cin >> n >> m;
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    sort(ALL(a));
    vector<lint> a2(m);
    FOR(i, n-m, n) a2[i-(n-m)] = a[i];
    a = a2;
    vector<vector<lint>> b(m);
    lint sumk = 0;
    vector<int> sidx(m);
    REP(i, m) {
      lint k;
      cin >> k;
      sidx[i] = sumk;
      sumk += k;
      b[i] = vector<lint>(k);
      REP(j, k) cin >> b[i][j];
    }
    vector<Bunsuu> bm(m, Bunsuu(0, 0));
    REP(i, m) REP(j, b[i].size()) {
      bm[i].p += b[i][j];
      bm[i].q++;
      bm[i].g = i;
    }
    sort(ALL(bm));
    vector<int> notok(m+1);
    REP(i, m) if(Bunsuu(a[i], 1) < bm[i]) notok[i+1]++;
    REP(i, m) notok[i+1] += notok[i];
    vector<int> lshift(m+1);
    FOR(i, 1, m) if(Bunsuu(a[i-1], 1) < bm[i]) lshift[i+1]++;
    REP(i, m) lshift[i+1] += lshift[i];
    vector<int> rshift(m+1);
    REP(i, m-1) if(Bunsuu(a[i+1], 1) < bm[i]) rshift[i+1]++;
    REP(i, m) rshift[i+1] += rshift[i];

    string ans = "";
    REP(i, sumk) ans += '0';
    REP(i, m) REP(j, bm[i].q) {
      Bunsuu bun = Bunsuu(bm[i].p - b[bm[i].g][j], bm[i].q - 1);
      auto itr = lower_bound(ALL(bm), bun);
      int idx = distance(bm.begin(), itr);
      if(idx > i) idx--;
      if(idx < i) {
        if(notok[idx] - notok[0] == 0 && Bunsuu(a[idx], 1) >= bun && rshift[i] - rshift[idx] == 0 && notok[m] - notok[i+1] == 0) ans[sidx[bm[i].g]+j] = '1';
      } else if(idx > i) {
        if(notok[i] - notok[0] == 0 && lshift[idx+1] - lshift[i+1] == 0 && Bunsuu(a[idx], 1) >= bun && notok[m] - notok[idx+1] == 0) ans[sidx[bm[i].g]+j] = '1';
      } else {
        if(notok[idx] - notok[0] == 0 && Bunsuu(a[idx], 1) >= bun && notok[m] - notok[idx+1] == 0) ans[sidx[bm[i].g]+j] = '1';
      }
    }
    cout << ans << "\n";
  }
}