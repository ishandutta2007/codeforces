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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> ans(a+b+c+d, 0);
    int idx = 0;
    if(a+b+c+d == 1) {
        cout << "YES" << endl;
        if(a == 1) {
            cout << 0 << endl;
        } else if(b == 1) {
            cout << 1 << endl;
        } else if(c == 1) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
        return 0;
    }
    if(c == 0 && d == 0 && a-b == 1) {
        cout << "YES" << endl;
        ans[idx] = 0;
        idx++;
        REP(i, b) {
            ans[idx] = 1;
            idx++;
            ans[idx] = 0;
            idx++;
        }
        REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
        cout << endl;
        return 0;
    }

    if(a == 0 && b == 0 && d-c == 1) {
        cout << "YES" << endl;
        ans[idx] = 3;
        idx++;
        REP(i, c) {
            ans[idx] = 2;
            idx++;
            ans[idx] = 3;
            idx++;
        }
        REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
        cout << endl;
        return 0;
    }

    if(b-a >= 0 && c-(b-a) == d) {
        cout << "YES" << endl;
        REP(i, a) {
            ans[idx] = 0;
            idx++;
            ans[idx] = 1;
            idx++;
        }
        REP(i, b-a) {
            ans[idx] = 2;
            idx++;
            ans[idx] = 1;
            idx++;
        }
        REP(i, d) {
            ans[idx] = 2;
            idx++;
            ans[idx] = 3;
            idx++;
        }
        REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
        cout << endl;
    } else if((b-1)-a >= 0 && c-((b-1)-a) == d) {
        cout << "YES" << endl;
        ans[idx] = 1;
        idx++;
        REP(i, a) {
            ans[idx] = 0;
            idx++;
            ans[idx] = 1;
            idx++;
        }
        REP(i, (b-1)-a) {
            ans[idx] = 2;
            idx++;
            ans[idx] = 1;
            idx++;
        }
        REP(i, d) {
            ans[idx] = 2;
            idx++;
            ans[idx] = 3;
            idx++;
        }
        REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
        cout << endl;
    } else if(b-a >= 0 && (c-1)-(b-a) == d) {
        cout << "YES" << endl;
        REP(i, a) {
            ans[idx] = 0;
            idx++;
            ans[idx] = 1;
            idx++;
        }
        REP(i, b-a) {
            ans[idx] = 2;
            idx++;
            ans[idx] = 1;
            idx++;
        }
        REP(i, d) {
            ans[idx] = 2;
            idx++;
            ans[idx] = 3;
            idx++;
        }
        ans[idx] = 2;
        idx++;
        REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
        cout << endl;
    } else if((b-1)-a >= 0 && (c-1)-((b-1)-a) == d) {
        cout << "YES" << endl;
        ans[idx] = 1;
        idx++;
        REP(i, a) {
            ans[idx] = 0;
            idx++;
            ans[idx] = 1;
            idx++;
        }
        REP(i, (b-1)-a) {
            ans[idx] = 2;
            idx++;
            ans[idx] = 1;
            idx++;
        }
        REP(i, d) {
            ans[idx] = 2;
            idx++;
            ans[idx] = 3;
            idx++;
        }
        ans[idx] = 2;
        idx++;
        REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}