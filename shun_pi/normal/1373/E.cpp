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
    int T;
    cin >> T;
    REP(t, T) {
        int n, k;
        cin >> n >> k;
        if(n < k*(k+1)/2) {
            cout << -1 << "\n";
            continue;
        }
        lint ans = 1e18;
        REP(i, 10-k) {
            lint sum = 0;
            REP(j, k+1) sum += i+j;
            if(n-sum >= 0 && (n-sum)%(k+1) == 0) {
                string s = to_string(i);      
                lint tmp4 = (n-sum)/(k+1);
                while(tmp4 > 0) {
                    if(tmp4 >= 9) {
                        s = '9' + s;
                        tmp4 -= 9;
                    } else {
                        s = (char)(tmp4+'0') + s;
                        tmp4 = 0;
                    }
                }
                //cout << s << endl;
                ans = min(ans, stoll(s));
            }
        }

        
        FOR(dignum, 1, 16) {
            lint tmp = 0;
            REP(i, dignum) tmp += 9LL*pow(10LL, (lint)i);
            REP(i, k) {
                lint tmp2 = tmp - i;
                lint sum = 0;
                REP(j, k+1) {
                    lint tmp3 = tmp2+j;
                    while(tmp3 > 0) {
                        sum += tmp3%10;
                        tmp3 /= 10;
                    }
                }
                if(n-sum >= 0 && (n-sum)%(k+1) == 0) {
                    string s = to_string(tmp2);
                    lint tmp4 = (n-sum)/(k+1);
                    bool mode = false;
                    while(tmp4 > 0) {
                        if(tmp4 >= 9) {
                            if(!mode) {
                                s = '8' + s;
                                tmp4 -= 8;
                            } else {
                                s = '9' + s;
                                tmp4 -= 9;
                            }
                        } else {
                            s = (char)(tmp4+'0') + s;
                            tmp4 = 0;
                        }
                        mode = true;
                    }
                    //cout << s << endl;
                    ans = min(ans, stoll(s));
                }
            }
        }
        if(ans == 1e18) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}