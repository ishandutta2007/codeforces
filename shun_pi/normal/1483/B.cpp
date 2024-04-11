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
lint gcd(lint a, lint b) {
  if(a < b) {
    swap(a, b);
  }
  while(b > 0) {
    lint r = a % b;
    a = b;
    b = r;
  }
  return a;
}
lint lcm(lint a, lint b) {
  return a * b / gcd(a, b);
}
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
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    vector<int> next(n);
    REP(i, n) next[i] = (i+1)%n;
    //vector<int> bef(n);
    //REP(i, n) next[i] = (n+i-1)%n;
    vector<int> check;
    REP(i, n) check.push_back(i);
    vector<int> ans;
    while(check.size() > 0) {
      vector<int> ncheck;
      for(int x : check) {
        if(next[x] == -1) continue;
        int target = next[x];
        if(gcd(a[x], a[target]) == 1) {
          ans.push_back(target);
          ncheck.push_back(x);
          next[x] = next[target];
          next[target] = -1;
        }
      }
      check = ncheck;
    }
    cout << ans.size() << " ";
    REP(i, ans.size()) cout << ans[i]+1 << (i!=ans.size()-1 ? " " : "");
    cout << "\n";
  }
}