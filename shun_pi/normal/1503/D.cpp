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
int la, lb, ra, rb;
vector<bool> isa;
int flip = 0;
bool inl(P p) {
  int a = p.first;
  int b = p.second;
  if(a < la || b > lb) return false;
  la = a;
  lb = b;
  if(isa[a]) flip++;
  return true;
}
bool inr(P p) {
  int a = p.first;
  int b = p.second;
  if(a > ra || b < rb) return false;
  ra = a;
  rb = b;
  if(isa[a]) flip++;
  return true;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i] >> b[i];
  REP(i, n) a[i]--;
  REP(i, n) b[i]--;
  isa = vector<bool>(2*n);
  REP(i, n) isa[a[i]] = true;
  set<P> st;
  REP(i, n) {
    st.insert(P(a[i], b[i]));
    st.insert(P(b[i], a[i]));
  }
  la = -1;
  lb = 2*n;
  ra = 2*n;
  rb = -1;
  int cnt = 0;
  int ans = 0;
  while(st.size() > 0) {
    cnt = 0;
    flip = 0;
    P p = *st.begin();
    st.erase(p);
    st.erase(P(p.second, p.first));
    cnt++;
    if(!inl(p)) {
      cout << -1 << endl;
      return 0;
    }
    int tmp = lb;
    bool did = false;
    while(st.size() > 0) {
      while(st.size() > 0) {
        P p2 = *prev(st.end());
        if(p2.first < tmp) break;
        did = true;
        st.erase(p2);
        st.erase(P(p2.second, p2.first));
        cnt++;
        if(!inr(p2)) {
          cout << -1 << endl;
          return 0;
        }
      }
      if(!did) break;
      tmp = rb;
      did = false;
      while(st.size() > 0) {
        P p2 = *st.begin();
        if(p2.first > tmp) break;
        did = true;
        st.erase(p2);
        st.erase(P(p2.second, p2.first));
        cnt++;
        if(!inl(p2)) {
          cout << -1 << endl;
          return 0;
        }
      }
      if(!did) break;
      tmp = lb;
      did = false;
    }
    ans += min(flip, cnt-flip);
  }
  if(la > ra || lb < rb) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
}