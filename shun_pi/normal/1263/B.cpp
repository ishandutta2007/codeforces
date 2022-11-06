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
        int n;
        cin >> n;
        vector<string> p(n);
        REP(i, n) cin >> p[i];
        int ans = 0;
        REP(i, n) {
            REP(k, n) {
                if(i == k) continue;
                if(p[i] == p[k]) {
                    ans++;
                    while(true) {
                        p[i] = p[i].substr(0, 3) + to_string((stoi(p[i].substr(3, 1)) + 9)%10);
                        bool flg = false;
                        REP(j, n) {
                            if(i == j) continue;
                            if(p[i] == p[j]) {
                                flg = true;
                                break;
                            }
                        }
                        if(!flg) break;
                    }
                    break;
                }
            }
            
        }
        cout << ans << endl;
        REP(i, n) cout << p[i] << endl;
    }
}