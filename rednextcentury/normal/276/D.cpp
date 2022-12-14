# include <iostream>
# include <string>
#include <cstdio>
#include <iomanip>
#include <queue>
# include <stack>
#include <ios>
using namespace std;
long long p[100];
int main()
{
    p[0] = 1;
    for (int i = 1; i <= 60; i++)
        p[i] = p[i - 1] * 2;
    long long l, r;
    cin >> l >> r;
    int i = 60;
    while (i >= 0)
    {
        if (l >= p[i] && r >= p[i])
        {
            l -= p[i];
            r -= p[i];
            i--;
        }
        else if (r >= p[i])
        {
            cout << p[i + 1] - 1 << endl;
            return 0;
        }
        else
            i--;
    }
    cout << 0 << endl;;
}