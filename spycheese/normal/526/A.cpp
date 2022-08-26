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

int main()
{
    ios::sync_with_stdio(false);

    int n;
    std::string s;
    std::cin >> n >> s;
    for (int i = 0; i < n; ++i)
        for (int j = 1; i+j*4 < n; ++j)
        {
            int cnt = 0;
            for (int k = 0; k < 5; ++k)
                if (s[i+j*k] == '*')
                    ++cnt;
            if (cnt == 5)
            {
                std::cout << "yes\n";
                return 0;
            }
        }
    std::cout << "no\n";

    return 0;
}