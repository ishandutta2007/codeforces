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
  vector<int> h(n);
  REP(i, n) cin >> h[i];
  REP(i, n) h[i]--;
  vector<lint> b(n);
  REP(i, n) cin >> b[i];
  vector<lint> htob(n);
  REP(i, n) htob[h[i]] = b[i];
  multiset<lint, greater<lint>> ms; 
  ms.insert(b[0]);
  multiset<PL, greater<PL>> hma;
  hma.insert(PL(h[0], 0));
  FOR(i, 1, n) {
    lint tmp = *ms.begin();
    vector<PL> erase;
    for(PL pl : hma) {
      if(pl.first < h[i]) break;
      erase.push_back(pl);
      chmax(tmp, pl.second);
      ms.erase(ms.find(pl.second+htob[pl.first]));
    }
    for(PL pl : erase) hma.erase(pl);
    hma.insert(PL(h[i], tmp));
    ms.insert(tmp + b[i]);
    lint ma = *ms.begin() + b[i];
    //cout << ma << endl;
    
  }
  cout << *ms.begin() << endl;
}