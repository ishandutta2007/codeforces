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
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int solve(string s, char a) {
    if(s.size() == 1) return s[0] == a ? 0 : 1;
    string s1 = s.substr(0, s.size()/2);
    string s2 = s.substr(s.size()/2, s.size()/2);
    int cnt1 = s1.size();
    REP(i, s1.size()) if(s1[i] == a) cnt1--;
    int cnt2 = s2.size();
    REP(i, s2.size()) if(s2[i] == a) cnt2--;
    return min(cnt1 + solve(s2, a+1), cnt2 + solve(s1, a+1));
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
        string s;
        cin >> s;
        cout << solve(s, 'a') << "\n";
    }
}