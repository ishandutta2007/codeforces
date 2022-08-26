#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

vector < pair < ll , ll > > ans;

int main()
{
    ios::sync_with_stdio(false);

    ll x;
    cin >> x;
    for (ll a = 1; a <= 10000000; ++a)
        if ((6*x) % a == 0)
        {
            ll cc = 6*x / a;
            cc -= (a-1)*(2*a-1);
            cc += 3*a*(a-1);
            ll nn = 6*a - 3*(a-1);
            if (cc % nn == 0)
            {
                ll b = cc / nn;
                if (b < a)
                    break;
                ans.push_back(make_pair(a, b));
            }
        }
    int nn = ans.size();
    for (int i = nn - 1; i >= 0; --i)
    {
        if (ans[i].first == ans[i].second)
            continue;
        ans.push_back(make_pair(ans[i].second, ans[i].first));
    }

    cout << ans.size() << "\n";
    for (auto xx : ans)
        cout << xx.first << " " << xx.second << "\n";

    return 0;
}