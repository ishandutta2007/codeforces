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

const int N = 200179;

string s[N];

int main()
{
    ios::sync_with_stdio(false);

    int n;
    unordered_set < string > ss;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = n - 1; i >= 0; --i)
        if (ss.count(s[i]) == 0)
        {
            cout << s[i] << "\n";
            ss.insert(s[i]);
        }

    return 0;
}