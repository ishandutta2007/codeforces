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

const int N = 100179;

int n, m;
int a[N], b[N], a2b[N];
vector < int > b2a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a2b[i];
        --a2b[i];
        b2a[a2b[i]].push_back(i);
    }
    bool amb = false;
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        --b[i];
        if (b2a[b[i]].empty())
        {
            cout << "Impossible\n";
            return 0;
        } else if (b2a[b[i]].size() > 1)
            amb = true;
    }
    if (amb)
    {
        cout << "Ambiguity\n";
        return 0;
    }
    cout << "Possible\n";
    for (int i = 0; i < m; ++i)
        cout << b2a[b[i]][0] + 1 << " ";
    cout << "\n";
    return 0;
}