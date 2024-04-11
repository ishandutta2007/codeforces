#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
int main()
{
    lint n, m, k;
    cin >> n >> m >> k;
    if(k > 4*n*m - 2*n - 2*m) {
        cout << "NO" << endl;
        return 0;
    }
    lint steps = 0;
    vector<lint> f;
    vector<string> s;
    REP(i, n) {
        if(m == 1) break;
        if(steps == k) break;
        lint ftmp = min(m-1, k-steps);
        steps += ftmp;
        f.push_back(ftmp);
        s.push_back("R");
        if(steps == k) break;
        if(n != 1 && i == n-1) break;
        ftmp = min(m-1, k-steps);
        steps += ftmp;
        f.push_back(ftmp);
        s.push_back("L");
        if(steps == k) break;
        ftmp = min((lint)1, k-steps);
        steps += ftmp;
        f.push_back(ftmp);
        s.push_back("D");
    }
    if(m == 1) {
        lint ftmp = min(n-1, k-steps);
        steps += ftmp;
        f.push_back(ftmp);
        s.push_back("D");
        if(steps != k) {
            ftmp = min(n-1, k-steps);
            steps += ftmp;
            f.push_back(ftmp);
            s.push_back("U");
        }
    }
    REP(i, m) {
        if(n == 1 || m == 1) break;
        if(steps == k) break;
        lint ftmp = min(n-1, k-steps);
        steps += ftmp;
        f.push_back(ftmp);
        s.push_back("U");
        if(steps == k) break;
        if(m != 1 && i == m-1) break;
        ftmp = min(n-1, k-steps);
        steps += ftmp;
        f.push_back(ftmp);
        s.push_back("D");
        if(steps == k) break;
        ftmp = min((lint)1, k-steps);
        steps += ftmp;
        f.push_back(ftmp);
        s.push_back("L");
    }
    cout << "YES" << endl;
    cout << f.size() << endl;
    REP(i, f.size()) {
        cout << f[i] << " " << s[i] << endl;
    }
}