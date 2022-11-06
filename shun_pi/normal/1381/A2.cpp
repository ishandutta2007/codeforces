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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool rev = false;
    int idx = 0;
    int idx1 = 1;
    int idx2 = n-1;
    vector<int> ans;
    IREP(i, n) {
      if((!rev && a[idx] == b[i]) || (rev && a[idx] != b[i])) {
        ans.push_back(1);
        a[idx] = (a[idx] == '0') ? '1' : '0';
      }
      ans.push_back(i+1);
      if(!rev) {
        rev = true;
        idx = idx2;
        idx2--;
      } else {
        rev = false;
        idx = idx1;
        idx1++;
      }
    }
    cout << ans.size() << " ";
    REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
    cout << "\n";
  }
}