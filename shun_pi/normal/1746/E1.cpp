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
  int n;
  cin >> n;
  vector<int> cand(n);
  REP(i, n) cand[i] = i+1;
  while(cand.size() > 2) {
    vector<int> s1, s2, s3;
    REP(i, cand.size()/3) s1.push_back(cand[i]);
    FOR(i, cand.size()/3, cand.size()*2/3) s2.push_back(cand[i]);
    FOR(i, cand.size()*2/3, cand.size()) s3.push_back(cand[i]);
    cout << "? " << s1.size() << " ";
    REP(i, s1.size()) cout << s1[i] << (i!=s1.size()-1 ? " " : "");
    cout << "\n";
    cout.flush();
    string ret1;
    cin >> ret1;
    vector<int> next_cand;
    if(ret1 == "YES") {
      string ret2;
      cout << "? " << s2.size() << " ";
      REP(i, s2.size()) cout << s2[i] << (i!=s2.size()-1 ? " " : "");
      cout << "\n";
      cout.flush();
      cin >> ret2;
      if(ret2 == "YES") {
        for(int x : s1) next_cand.push_back(x);
        for(int x : s2) next_cand.push_back(x);
      } else {
        for(int x : s1) next_cand.push_back(x);
        for(int x : s3) next_cand.push_back(x);
      }
    } else {
      string ret2;
      cout << "? " << s1.size() << " ";
      REP(i, s1.size()) cout << s1[i] << (i!=s1.size()-1 ? " " : "");
      cout << "\n";
      cout.flush();
      cin >> ret2;
      if(ret2 == "NO") {
        for(int x : s2) next_cand.push_back(x);
        for(int x : s3) next_cand.push_back(x);
      } else {
        string ret3;
        cout << "? " << s2.size() << " ";
        REP(i, s2.size()) cout << s2[i] << (i!=s2.size()-1 ? " " : "");
        cout << "\n";
        cout.flush();
        cin >> ret3;
        if(ret3 == "YES") {
          for(int x : s1) next_cand.push_back(x);
          for(int x : s2) next_cand.push_back(x);
        } else {
          for(int x : s1) next_cand.push_back(x);
          for(int x : s3) next_cand.push_back(x);
        }
      }
      
    }
    cand = next_cand;
  }
  REP(i, cand.size()) {
    cout << "! " << cand[i] << "\n";
    cout.flush();
    string ret;
    cin >> ret;
    if(ret == ":)") return 0;
  }
}