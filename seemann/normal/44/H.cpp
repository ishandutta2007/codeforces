#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>

#define clr(a) memset(a, 0, sizeof(a))
#define fori(a) for(int i = 0; i < a; i++)
#define forj(a) for(int j = 0; j < a; j++)
#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define ll long long

using namespace std;

set <string> S;

string num;
ll ans = 0;
ll dp[100][10];

/*void rec(int i, string t) {
    if (i==num.length()) {
        if (t!=num) ++ans;
        return;
    }
    double tmp = double(s[i]+t[i-1]) / 2.0;

}*/

int main()
{
    cin >> num;
    ll ans = 0;
    FOR(i, num.length()) num[i]-='0';
//    FOR(i,10) solve(1, string((char)i));
    FOR(i,10) dp[0][i] = 1;
    //FOR(i, 10) dp[0][9] = 1;
    for (int i=1; i<num.length(); ++i) {
        FOR(j,10) {
            dp[i][(num[i]+j)/2] += dp[i-1][j];
            if ( (num[i]+j)%2 != 0)
                dp[i][(num[i]+j)/2 + 1] += dp[i-1][j];
        }
    }
    FOR (i, 10) ans+=dp[num.length()-1][i];

    bool b = true;
    for (int i=1; i<num.length(); ++i) {
        ll t = num[i]+num[i-1];
        if (t/2 == num[i] || ( (t%2==1 && (t/2+1)==num[i])) )
            b = b;
        else {b = false;break;}
    }
    if (b) --ans;

    cout << ans;
    return 0;
}