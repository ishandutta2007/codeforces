#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define itr(x) x::iterator

typedef vector < int > vi;

int gcd(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int
main()
{
    int n;
    while (cin >> n)
    {
        vi cur(n, 0);
        int mx = 0, g = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> cur[i];
            mx = max(mx, cur[i]);
            g = gcd(g, cur[i]);
        }
        mx /= g;
        if ((mx - n) & 1)
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
    return 0;
}