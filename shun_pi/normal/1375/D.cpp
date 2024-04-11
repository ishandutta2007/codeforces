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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    REP(t, T) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        vector<int> x;
        while(true) {
            vector<int> cnt(n+1);
            REP(i, n) cnt[a[i]]++;
            int mex = 0;
            REP(i, n+1) if(cnt[i] == 0) {
                mex = i;
                break;
            }
            int mi = 0;
            REP(i, n+1) if(cnt[i] > 0 && a[i] != i) {
                mi = i;
                break;
            }
            if(mex != n && a[mex] != mex) {
                a[mex] = mex;
                x.push_back(mex+1);
            } else {
                REP(i, n) {
                    if(a[i] == mi) {
                        a[i] = mex;
                        x.push_back(i+1);
                        break;
                    }
                }
            }
            bool flg2 = true;
            REP(i, n) if(a[i] != i) flg2 = false;
            if(flg2) break;
        }
        cout << x.size() << "\n";
        REP(i, x.size()) cout << x[i] << (i!=x.size()-1 ? " " : "");
        cout << "\n";
    }
}