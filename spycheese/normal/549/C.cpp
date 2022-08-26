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

    int n, k, s0=0, s1=0;
    cin >> n >> k;
    k = n - k;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (a%2)
            ++s1;
        else
            ++s0;
    }

    for (int i = 0; i < k; ++i)
    {
        if (s0==0)
        {
            --s1;
            continue;
        } else if (s1 == 0)
        {
            --s0;
            continue;
        }
        if (i%2 == (k-1)%2)
        {
            if (i == k-1)
            {
                if (i%2 == 0)
                {
                    if (s1%2 == 0 && s1 != 0)
                        --s1;
                    else
                        --s0;
                } else {
                    if (s1%2 == 1)
                        --s1;
                    else
                        --s0;
                }
            } else if (s0 > s1)
                --s0;
            else if (s0 < s1)
                --s1;
            else if (i%2 == 1)
                --s1;
            else
                --s0;
        } else {
            bool v1 = (i%2 == 1);
            bool v0 = (i%2 == 1 && (s1-((k-i)-s0)) % 2 == 0);
            v0 |= (i%2 == 0 && (s1-((k-i)-s0)) % 2 == 1);
            v0 &= (s0 <= k-i);
            v1 &= (s1 <= k-i);
            if (v0 && v1)
            {
                if (s0 < s1 && s0 != 0)
                    --s0;
                else
                    --s1;
            } else if (v1)
                --s1;
            else
                --s0;
        }
    }
    if (s1 % 2 == 1)
        cout << "Stannis\n";
    else
        cout << "Daenerys\n";

    return 0;
}