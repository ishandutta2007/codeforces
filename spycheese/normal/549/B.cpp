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

const int N = 179;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    static string s[N];
    static int a[N];
    cin >> n;
    vector < int > ans;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    while (true)
    {
        int d = -1;
        for (int i = 0; i < n; ++i)
            if (a[i] == 0)
            {
                d = i;
                break;
            }
        if (d == -1)
            break;
        ans.push_back(d+1);
        for (int i = 0; i < n; ++i)
            if (s[d][i] == '1')
                --a[i];
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}