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

int n;
ll m, s, d;
ll x[N];
int prv[N];
ll nextJ = 0;
int nextP = -1;

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m >> s >> d;
    x[0] = -1;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    ++n;
    sort(x, x + n);
    for (int i = 0; i < n; ++i)
    {
        if (nextJ < x[i] + 1)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        prv[i] = nextP;
        if (i != n - 1)
            if ((x[i + 1] - 1) - (x[i] + 1) >= s)
            {
                nextJ = x[i + 1] - 1 + d;
                nextP = i;
            }
    }
    vector < int > ans;
    int curr = n - 1;
    while (curr != -1)
    {
        ans.push_back(curr);
        curr = prv[curr];
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < sz(ans) - 1; ++i)
    {
        int co = ans[i];
        int no = ans[i + 1];
        cout << "RUN " << (x[co + 1] - 1) - (x[co] + 1) << "\n";
        cout << "JUMP " << (x[no] + 1) - (x[co + 1] - 1) << "\n";
    }
    if (x[n - 1] + 1 != m)
        cout << "RUN " << m - (x[n - 1] + 1) << "\n";

    return 0;
}