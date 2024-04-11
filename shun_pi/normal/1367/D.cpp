#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin >> Q;
    REP(q, Q) {
        string s;
        cin >> s;
        vector<int> cnt(26);
        REP(i, s.size()) cnt[s[i]-'a']++;
        int m;
        cin >> m;
        vector<int> b(m);
        REP(i, m) cin >> b[i];
        vector<char> ans(m, 0);
        int cntidx = 25;
        int fillcnt = 0;
        while(true) {
            set<int> nextfill;
            REP(i, m) {
                if(ans[i] == 0) {
                    int sum = 0;
                    REP(j, m) if(ans[j] != 0) sum += abs(j-i);
                    if(sum == b[i]) nextfill.insert(i);
                }
            }
            while(true) {
                if(cnt[cntidx] >= nextfill.size()) break;
                cntidx--;
            }
            for(int x : nextfill) ans[x] = cntidx + 'a';
            fillcnt += nextfill.size();
            cntidx--;
            if(fillcnt == m) break;
        }
        REP(i, m) cout << ans[i];
        cout << "\n";

    }
}