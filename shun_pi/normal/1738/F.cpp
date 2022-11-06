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
    vector<int> d(n);
    REP(i, n) cin >> d[i];
    set<P, greater<P>> st;
    REP(i, n) if(d[i] > 1) st.insert(P(d[i], i));
    int cptr = 0;
    vector<int> c(n, -1);
    REP(i, n) if(d[i] <= 1) {
      c[i] = cptr;
      cptr++;
    }
    while(!st.empty()) {
      P p = *st.begin();
      st.erase(st.begin());
      c[p.second] = cptr;
      int nsum = 1;
      lint dsum = p.first;
      vector<int> tmp;
      tmp.push_back(p.second);
      int cptrtmp = cptr;
      while(dsum > nsum * nsum) {
        cout << "? " << p.second+1 << "\n";
        cout.flush();
        int e;
        cin >> e;
        e--;
        tmp.push_back(e);
        st.erase(P(d[e], e));
        if(c[e] != -1) {
          cptrtmp = c[e];
          REP(i, n) if(c[i] == cptrtmp) {
            nsum++;
            dsum += d[i];
          }
          for(int x : tmp) c[x] = cptrtmp;
        } else {
          nsum++;
          dsum += d[e];
          c[e] = cptrtmp;
        }
        
      }
      cptr++;
    }
    cout << "! ";
    REP(i, n) cout << c[i]+1 << (i!=n-1 ? " " : "");
    cout << "\n";
    cout.flush();
  }
}