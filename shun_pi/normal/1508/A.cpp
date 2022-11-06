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
    vector<string> s(3);
    REP(i, 3) cin >> s[i];
    vector<int> zeros(3), ones(3);
    REP(i, 3) REP(j, 2*n) {
      if(s[i][j]  == '0') zeros[i]++;
      else ones[i]++;
    }
    bool ok = false;
    REP(i, 3) FOR(j, i+1, 3) {
      if(ok) break;
      string ans = "";
      REP(k, 2*n) {
        if(s[i][k] == s[j][k]) ans += s[i][k];
        else ans += "01";
      }
      if(ans.size() <= 3*n) {
        while(ans.size() < 3*n) ans += "0";
        cout << ans << "\n";
        ok = true;
      }
      if(ok) break;
      if(max(zeros[i], zeros[j]) + ones[i] + ones[j] <= 3*n) {
        int ptri = 0;
        int ptrj = 0;
        string ans = "";
        while(ptri < 2*n || ptrj < 2*n) {
          if(ptri == 2*n) {
            ans += s[j][ptrj];
            ptrj++;
          } else if(ptrj == 2*n) {
            ans += s[i][ptri];
            ptri++;
          } else if(s[i][ptri] == '0' && s[j][ptrj] == '0') {
            ans += '0';
            ptri++;
            ptrj++;
          } else if(s[i][ptri] == '1') {
            ans += '1';
            ptri++;
          } else {
            ans += '1';
            ptrj++;
          }
        }
        while(ans.size() < 3*n) ans += "0";
        cout << ans << "\n";
        ok = true;
      } else if(max(ones[i], ones[j]) + zeros[i] + zeros[j] <= 3*n) {
        int ptri = 0;
        int ptrj = 0;
        string ans = "";
        while(ptri < 2*n || ptrj < 2*n) {
          if(ptri == 2*n) {
            ans += s[j][ptrj];
            ptrj++;
          } else if(ptrj == 2*n) {
            ans += s[i][ptri];
            ptri++;
          } else if(s[i][ptri] == '1' && s[j][ptrj] == '1') {
            ans += '1';
            ptri++;
            ptrj++;
          } else if(s[i][ptri] == '0') {
            ans += '0';
            ptri++;
          } else {
            ans += '0';
            ptrj++;
          }
        }
        while(ans.size() < 3*n) ans += "0";
        cout << ans << "\n";
        ok = true;
      }
    }
  }
}