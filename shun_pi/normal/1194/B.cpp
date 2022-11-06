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
    vector<int> ans(q);
    REP(k, q) {
        int n, m;
        cin >> n >> m;
        vector<string> c(n);
        vector<int> rcnt(n, 0);
        vector<int> ccnt(m, 0);
        REP(i, n) {
            cin >> c[i];
            REP(j, m) {
                if(c[i][j] == '*') {
                    rcnt[i]++;
                }
            }
        }
        REP(i, m) {
            REP(j, n) {
                if(c[j][i] == '*') {
                    ccnt[i]++;
                }
            }
        }
        int min = MOD;
        REP(i, n) {
            REP(j, m) {
                if(c[i][j] == '*') {
                    if(n + m - rcnt[i] - ccnt[j] < min) {
                        min = n + m - rcnt[i] - ccnt[j];
                    }
                } else {
                    if(n + m - rcnt[i] - ccnt[j] - 1< min) {
                        min = n + m - rcnt[i] - ccnt[j] - 1;
                    }
                }
            }
        }
        ans[k] = min;
    }
    REP(i, q) {
        cout << ans[i] << endl;
    }
}