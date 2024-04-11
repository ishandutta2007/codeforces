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

const int N = 100179;

int n, a[N], nd[N];

int main()
{
    ios::sync_with_stdio(false);

    std::cin >> n;
    int m = (1 << (n + 1)) - 1;
    int mx = 0;
    for (int i = 1; i < m; ++i)
    {
        int x;
        std::cin >> x;
        a[i] = a[(i-1)/2] + x;
        mx = std::max(mx, a[i]);
    }
    for (int i = (1 << n) - 1; i < m; ++i)
        nd[i] = mx - a[i];
    for (int i = (1 << n) - 2; i >= 1; --i)
    {
        nd[i] = std::min(nd[i*2+1], nd[i*2+2]);
        nd[i*2+1] -= nd[i];
        nd[i*2+2] -= nd[i];
    }
    int s = 0;
    for (int i = 1; i < m; ++i)
        s += nd[i];
    std::cout << s << "\n";

    return 0;
}