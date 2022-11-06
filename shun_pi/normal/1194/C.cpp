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
    int q;
    cin >> q;
    while(q-->0) {
        string s, t, p;
        cin >> s >> t >> p;
        int sidx = 0;
        int tidx = 0;
        while(sidx < s.size() && tidx < t.size()) {
            if(s[sidx] == t[tidx]) {
                sidx++;
            }
            tidx++;
        }
        if(sidx < s.size()) {
            cout << "NO" << endl;
            continue;
        }
        vector<int> sc(26);
        vector<int> tc(26);
        vector<int> pc(26);
        REP(i, s.size()) sc[s[i] - 'a']++;
        REP(i, t.size()) tc[t[i] - 'a']++;
        REP(i, p.size()) pc[p[i] - 'a']++;
        bool flg = true;
        REP(i, 26) {
            if(sc[i] + pc[i] < tc[i]) {
                flg = false;
                break;
            }
        }
        if(flg) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}