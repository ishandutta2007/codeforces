#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
string s;
int c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s;
    N = s.length();
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'b')
            c[i] = 1;
        else
            c[i] = 0;
        c[i+N] = c[i];
    }

    int res = 1;
    int cc = 1;
    for (int i = 1; i < 2 * N; i++)
    {
        if (c[i] != c[i-1])
        {
            cc++;
        }
        else
            cc = 1;
        res = max (res, cc);
    }
    res = min (res, N);

    cout << res << "\n";
    return 0;
}