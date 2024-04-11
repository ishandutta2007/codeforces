#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))

using namespace std;

// ========================================================================= //

const int N = 100179;

int main()
{
    ios::sync_with_stdio(false);

    int f, i, t;
    cin >> f >> i >> t;
    static int a[N];
    int kitten = 0;
    for (int j = 0; j < f; ++j)
    {
        string s;
        cin >> s;
        for (int k = 0; k < i; ++k)
        {
            if (s[k] == 'Y')
            {
                ++a[k];
                if (a[k] == t)
                    ++kitten;
            }
        }
    }
    cout << kitten << "\n";
    return 0;
}