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
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> b(n);
    REP(i, n) cin >> b[i];
    REP(i, n) b[i]--;
    vector<int> btmp(b);
    vector<int> cnt(n+1);
    REP(i, n) cnt[b[i]]++;
    int emptycol = 0;
    REP(i, n+1) if(cnt[i] == 0) {
      emptycol = i;
      break;
    }
    vector<P> cnt2(n+1);
    REP(i, n+1) cnt2[i] = make_pair(cnt[i], i);
    sort(ALL(cnt2), greater<P>());
    int emptynum = n - y;
    int numnum = y - x;
    vector<P> tmp;
    vector<int> numcnt(n+1);
    while(emptynum > 0 || numnum > 0) {
      REP(i, n+1) {
        if((emptynum == 0 && numnum == 0) || cnt2[i].first == 0) break;
        if(numnum > 0) {
          tmp.push_back(make_pair(cnt2[i].second,cnt2[i].second));
          numcnt[cnt2[i].second]++;
          cnt2[i].first--;
          numnum--;
        } else {
          tmp.push_back(make_pair(cnt2[i].second,200000));
          numcnt[cnt2[i].second]++;
          cnt2[i].first--;
          emptynum--;
        }
      }
    }
    sort(ALL(tmp));
    int numcntmax = 0;
    REP(i, n+1) numcntmax = max(numcntmax, numcnt[i]);

    multiset<P> st;
    REP(i, tmp.size()) st.insert(make_pair(tmp[(i+numcntmax)%tmp.size()].first, tmp[i].second));
    bool flg = false;
    for(P p : st) {
      if(p.first == p.second) {
        flg = true;
        break;
      }
    }
    if(flg) {
      cout << "NO" << "\n";
      continue;
    }
    
    REP(i, n) {
      auto itr = st.lower_bound(make_pair(b[i], 0));
      if(itr != st.end() && (*itr).first == b[i]) {
        b[i] = (*itr).second == 200000 ? emptycol : (*itr).second;
        st.erase(itr);
      }
    }

    cout << "YES" << "\n";
    REP(i, n) cout << b[i]+1 << (i!=n-1 ? " " : "");
    cout << "\n";
  }
}