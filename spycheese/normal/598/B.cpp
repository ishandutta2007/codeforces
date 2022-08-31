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

char s[N], s1[N];
int m;

int main()
{
    ios::sync_with_stdio(false);

    cin >> s >> m;
    for (int i = 0; i < m; ++i)
    {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        --r;
        k %= r - l + 1;
        memcpy(s1 + k, s + l, sizeof(char)*(r-l+1-k));
        memcpy(s1, s + l + (r-l+1-k), sizeof(char)*k);
        memcpy(s+l, s1, sizeof(char)*(r-l+1));
    }
    cout << s << "\n";

    return 0;
}