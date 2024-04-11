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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  multiset<PL> st;
  multiset<PL, greater<PL>> rest;
  multiset<lint, greater<lint>> fire;
  fire.insert(0);
  rest.insert(PL(0, 0));
  lint stsum = 0;
  lint allsum = 0;
  lint stfirecnt = 0;
  REP(i, n) {
    lint tp, d;
    cin >> tp >> d;
    if(d > 0) {
      if(tp == 0) fire.insert(d);
      allsum += d;
      rest.insert(PL(d, tp));
      if(tp == 1 || (st.size() > 0 && (*(st.begin())).first <= (*(rest.begin())).first)) {
        PL tmp = *(rest.begin());
        if(tp == 0 && st.size() > 0) {
          if((*(st.begin())).second == 0) stfirecnt--;
          rest.insert(*(st.begin()));
          stsum -= (*(st.begin())).first;
          st.erase(st.find(*st.begin()));
        }
        st.insert(tmp);
        rest.erase(rest.find(tmp));
        if(tmp.second == 0) stfirecnt++;
        stsum += tmp.first;
      }
    } else {
      d = -d;
      allsum -= d;
      if(tp == 0) fire.erase(fire.find(d));
      if(rest.find(PL(d, tp)) != rest.end()) {
        rest.erase(rest.find(PL(d, tp)));
        if(tp == 1) {
          if((*(st.begin())).second == 0) stfirecnt--;
          rest.insert(*(st.begin()));
          stsum -= (*(st.begin())).first;
          st.erase(st.find(*st.begin()));
        }
      } else {
        if(tp == 0) stfirecnt--;
        stsum -= d;
        st.erase(st.find(PL(d, tp)));
        if(tp == 0) {
          if((*(rest.begin())).second == 0) stfirecnt++;
          stsum += (*(rest.begin())).first;
          st.insert(*(rest.begin()));
          rest.erase(rest.find(*rest.begin()));
        }
      }
    }
    //cout << stsum << " " << allsum << " " << stfirecnt << " " << st.size() << " " << fire.size() << endl;
    if(stfirecnt > 0) cout << stsum+allsum << endl;
    else cout << stsum+allsum - (st.size()>0 ? (*(st.begin())).first - *fire.begin() : 0) << endl;
  }
}