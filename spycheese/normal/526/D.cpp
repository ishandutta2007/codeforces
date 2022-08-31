#include <bits/stdc++.h>

#define sz(x) ((int)(x).size())
#define mp(x,y) make_pair((x), (y))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = {1, 0, -1,  0, 1, -1,  1, -1};
const int DY[] = {0, 1,  0, -1, 1, -1, -1,  1};
// EOTPL

const int N = 2000179;

int ok[N];
int z[N];

void set1(int l, int r)
{
    ++ok[l];
    --ok[r + 1];
}

int main()
{
    ios::sync_with_stdio(false);

    ll n, k;
    std::string s;
    std::cin >> n >> k >> s;

    if (k == 1)
    {
        for (int i = 0; i < n; ++i)
            std::cout << 1;
        return 0;
    }

    int b = 0;
    int bz = 0;
    z[0] = 0;
    for (unsigned i = 1; i < s.length(); ++i)
    {
        unsigned bz = b + z[b];
        if (i >= bz)
        {
            z[i] = 0;
            for (unsigned j = i; j < s.length() && s[j] == s[j - i]; ++j)
                ++z[i];
            b = i;
        } else if (z[i - b] + i - b < z[b])
            z[i] = z[i - b];
        else
        {
            z[i] = bz - i;
            for (unsigned j = z[i] + i; j < s.length() && s[j] == s[j - i]; ++j)
                ++z[i];
            b = i;
        }

        if (i + z[i] >= k*i)
            set1(k*i, std::min(i + z[i], (int)(k+1)*i));
    }

    int cc = 0;
    for (int i = 1; i <= n; ++i)
    {
        cc += ok[i];
        if (cc > 0)
            std::cout << 1;
        else
            std::cout << 0;
    }

    return 0;
}