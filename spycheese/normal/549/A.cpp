#include <bits/stdc++.h>

#ifndef LOCAL
#define stderr lorem_ipsum
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

const int N = 100179;

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    static string s[N];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
        int ans = 0;
    for (int i = 0; i < n-1; ++i)
        for (int j = 0; j < m-1; ++j)
        {
            string ss;
            ss += s[i][j];
            ss += s[i+1][j];
            ss += s[i+1][j+1];
            ss += s[i][j+1];
            sort(ss.begin(), ss.end());
            if (ss == "acef")
                ++ans;
        }
    cout << ans;

    return 0;
}