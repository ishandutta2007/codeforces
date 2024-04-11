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
    string s;
    cin >> s;
    vector<int> cnt(26);
    REP(i, s.size()) cnt[s[i]-'a']++;
    int mini = -1;
    int kind = 0;
    REP(i, 26) {
      if(cnt[i] == 1 && mini == -1) mini = i;
      if(cnt[i] >= 1) kind++;
    }
    if(kind == 1) {
      cout << s << "\n";
      continue;
    } else if(mini != -1) {
      string t = "";
      t += mini + 'a';
      cnt[mini]--;
      int idx = 0;
      while(idx < 26) {
        if(cnt[idx] == 0) {
          idx++;
          continue;
        }
        t += idx + 'a';
        cnt[idx]--;
      }
      cout << t << "\n";
      continue;
    }
    int i1 = -1;
    int i2 = -1;
    int i3 = -1;
    REP(i, 26) if(cnt[i] > 0) {
      if(i1 == -1) i1 = i;
      else if(i2 == -1) i2 = i;
      else if(i3 == -1) i3 = i;
    }
    string t = "";
    t += i1 + 'a';
    t += i1 + 'a';
    vector<int> c(26);
    REP(i, 26) c[i] = cnt[i]; 
    c[i1] -= 2;
    int idx = 0;
    while(true) {
      if((idx < 26 && c[idx] == 0) || idx == i1) {
        idx++;
        continue;
      }
      if(c[i1] == 0 || t[t.size()-1] == i1 + 'a') {
        if(idx >= 26) break;
        t += idx + 'a';
        c[idx]--;
      } else {
        t += i1 + 'a';
        c[i1]--;
      }
    }
    if(t.size() == s.size()) {
      cout << t << "\n";
      continue;
    }
    string u = "";
    u += i1 + 'a';
    u += i2 + 'a';
    vector<int> d(cnt);
    d[i1]--;
    d[i2]--;
    if(kind == 2) {
      REP(i, d[i2]) u += i2 + 'a';
      REP(i, d[i1]) u += i1 + 'a';
    } else {
      REP(i, d[i1]) u += i1 + 'a';
      d[i1] = 0;
      u += i3 + 'a';
      d[i3]--;
      int idx = 0;
      while(idx < 26) {
        if(d[idx] == 0) idx++;
        else {
          u += idx + 'a';
          d[idx]--;
        }
      }
    }
    cout << u << "\n";
  }
}