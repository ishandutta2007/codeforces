#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> S(k);
        vector<bool> used(n);
        REP(i, k) {
            int c;
            cin >> c;
            REP(j, c) {
                int x;
                cin >> x;
                S[i].push_back(x);
                x--;
                used[x] = true;
            }
            
        }
        vector<int> subset;
        REP(i, n) if(used[i]) subset.push_back(i+1);
        cout << "? " << subset.size() << " ";
        REP(i, subset.size()) cout << subset[i] << (i!=subset.size()-1 ? " " : "");
        cout << "\n";
        cout.flush();
        int subsetmax;
        cin >> subsetmax;

        int l = 0;
        int r = k;
        while(r-l > 1) {
            int m = (l+r) / 2;
            subset.clear();
            FOR(i, l, m) {
                REP(j, S[i].size()) subset.push_back(S[i][j]);
            }
            cout << "? " << subset.size() << " ";
            REP(i, subset.size()) cout << subset[i] << (i!=subset.size()-1 ? " " : "");
            cout << "\n";
            cout.flush();
            int ret;
            cin >> ret;
            if(ret == subsetmax) {
                r = m;
            } else {
                l = m;
            }
        }

        subset.clear();
        REP(i, k) {
            if(i == l) continue;
            REP(j, S[i].size()) subset.push_back(S[i][j]);
        }
        REP(i, n) if(!used[i]) subset.push_back(i+1);
        cout << "? " << subset.size() << " ";
        REP(i, subset.size()) cout << subset[i] << (i!=subset.size()-1 ? " " : "");
        cout << "\n";
        cout.flush();
        int ret;
        cin >> ret;
        if(ret > subsetmax) subsetmax = ret;

        cout << "! ";
        REP(i, k) {
            if(i == l) {
                cout << ret;
            } else {
                cout << subsetmax;
            }
            cout << (i!=k-1 ? " " : "");
        }
        cout << "\n";
        cout.flush();
        string s;
        cin >> s;
    }
}