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
    REP(t, T ){
        int r, c, k;
        cin >> r >> c >> k;
        vector<string> map(r);
        REP(i, r) {
            cin >> map[i];
        }
        int rice = 0;
        REP(i, r) {
            REP(j, c) {
                if(map[i][j] == 'R') {
                    rice++;
                }
            }
        }
        int a = rice / k;
        int b = rice % k;
        vector<int> ricelist(k, a);
        REP(i, b) {
            ricelist[i]++;
        }
        vector<vector<char>> ans(r, vector<char>(c));
        int nowk = 0;
        REP(i, r) {
            if(i%2 == 0) {
                REP(j, c) {
                    if(nowk >= 36) {
                        ans[i][j] = 'a' + (nowk-36);
                    } else if(nowk >= 10) {
                        ans[i][j] = 'A' + (nowk-10);
                    } else {
                        ans[i][j] = '0' + nowk;
                    }
                    if(map[i][j] == 'R') {
                        ricelist[nowk]--;
                    }
                    if(ricelist[nowk] == 0 && nowk != k-1) {
                        nowk++;
                    }
                }
            } else {
                IREP(j, c) {
                    if(nowk >= 36) {
                        ans[i][j] = 'a' + (nowk-36);
                    } else if(nowk >= 10) {
                        ans[i][j] = 'A' + (nowk-10);
                    } else {
                        ans[i][j] = '0' + nowk;
                    }
                    if(map[i][j] == 'R') {
                        ricelist[nowk]--;
                    }
                    if(ricelist[nowk] == 0 && nowk != k-1) {
                        nowk++;
                    }
                }
            }
        }

        REP(i, r) {
            REP(j, c) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
}