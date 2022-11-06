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
    int T;
    cin >> T;
    REP(t, T) {
        int n, m;
        cin >> n >> m;
        vector<int> l(m);
        vector<int> r(m);
        REP(i, m) {
            cin >> l[i] >> r[i];
        }
        vector<bool> used(3*n+1);
        vector<int> edges;
        REP(i, m) {
            if(used[l[i]] == false && used[r[i]] == false) {
                edges.push_back(i+1);
                used[l[i]] = true;
                used[r[i]] = true;
            }
        }
        if(edges.size() >= n ) {
            cout << "Matching" << endl;
            REP(i, n) cout << edges[i] << (i!=n-1 ? " " : "");
            cout << endl;
        } else {
            cout << "IndSet" << endl;
            vector<int> ans(n);
            int idx = 0;
            FOR(i, 1, 3*n+1) {
                if(used[i] == false) {
                    ans[idx] = i;
                    idx++;
                }
                if(idx == n) break;
            }
            REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
            cout << endl;
        }
    }
}