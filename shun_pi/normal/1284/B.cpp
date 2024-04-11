#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
int main()
{
    lint n;
    cin >> n;
    vector<vector<lint>> s;
    REP(i, n) {
        lint l;
        cin >> l;
        s.emplace_back();
        REP(j, l) {
            lint ss;
            cin >> ss;
            s[i].push_back(ss);
        }
    }
    vector<bool> isascent(n, false);
    REP(i, n) {
        FOR(j, 1, s[i].size()) {
            if(s[i][j] > s[i][j-1]) {
                isascent[i] = true;
                break;
            }
        }
    }
    vector<lint> left(1000001);
    vector<lint> right(1000001);
    REP(i, n) {
        if(!isascent[i]) {
            left[s[i][s[i].size()-1]]++;
            right[s[i][0]]++;
        }
    }
    lint ans = 0;
    REP(i, 1000001) {
        if(i != 0) right[i] += right[i-1];
        ans += left[i] * right[i];
    }
    ans = n*n - ans;
    cout << ans << endl;
}