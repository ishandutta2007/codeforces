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
const int INF = 1000000000;

int main()
{
    int n;
    cin >> n >> ws;
    char s[1001];
    scanf("%s", &s);
    int h = 0;
    FOR(i, n)
    {
        if (s[i] == 'H') h++;
    }
    int _min = INF;
    FOR(i, n)
    {
        int ans = 0;
        FOR(j, h)
        {
            if (s[(i + j) % n] == 'T') ans++;
        }
        _min = min(ans, _min);
    }
    cout << _min;

    return 0;
}