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
#include <vector>

using namespace std;

#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))
#define ll long long
//define _in_s(a, b) (((a) < h)&&((a) >= 0)&&((b) < w)&&((b) >= 0))

int main()
{
    int n;
    cin >> n;
    int a = 0;
    FOR(i, n - 1)
    {
        a += i + 1;
        a %= n;
        cout << a + 1 << ' ';
    }

    return 0;
}