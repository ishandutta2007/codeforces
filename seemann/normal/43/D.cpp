#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))
#define ll long long

const int INF = 1000000000;
const double EPS = 1e-8;
using namespace std;


void _kill()
{
    cout << "NO";
    exit(0);
}

int a[3];


int main()
{
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 2)
    {
        cout << 0 << '\n' << "1 1\n1 2\n1 1";
        return 0;
    }
    if (n == 2 && m == 1)
    {
        cout << 0 << '\n' << "1 1\n2 1\n1 1";
        return 0;
    }
    if (n == 1)
    {
        cout << 1 << '\n';
        cout << 1 << ' ' << m << ' ' << 1 << ' ' << 1 << '\n';
        FOR(i, m)
            cout << 1 << ' ' << i+1 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return 0;
    }

    if (m == 1)
    {
        cout << 1 << '\n';
        cout << n << ' ' << 1 << ' ' << 1 << ' ' << 1 << '\n';
        FOR(i, n)
            cout << i+1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return 0;
    }

    if (n % 2 == 0)
    {
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        FOR(i, n)
            if (i % 2 == 0)
                for (int j = 2; j <= m; j++)
                    cout << i + 1 << ' ' << j << '\n';
                else
                for (int j = m; j >= 2; j--)
                    cout << i + 1 << ' ' << j << '\n';
        for (int i = n; i>= 1;i--)
            cout << i << ' ' << 1 << '\n';
        return 0;
    }
    if (m % 2 == 0)
    {
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        FOR(i, m)
            if (i % 2 == 0)
                for (int j = 2; j <= n; j++)
                    cout << j << ' ' << i + 1 << '\n';
                else
                for (int j = n; j >= 2; j--)
                    cout << j << ' ' << i + 1<< '\n';
        for (int i = m; i>= 1;i--)
            cout << 1 << ' ' << i << '\n';
        return 0;
    }
    cout << 1 << '\n';
    cout << n << ' ' << m << ' ' << 1 << ' ' << 1 << '\n';
    //cout << 1 << ' ' << 1 << '\n';
    FOR(i, m)
        if (i % 2 == 0)
            for (int j = 1; j <= n; j++)
                cout << j << ' ' << i + 1 << '\n';
                else
                for (int j = n; j >= 1; j--)
                    cout << j << ' ' << i + 1 << '\n';
    cout << 1 << ' ' << 1 << '\n';

    return 0;

}