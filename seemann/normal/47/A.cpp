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
//const ll INF = (ll)1000000000 * (ll)1000000000;
const int INF = 1000000000;


int main()
{
    //freopen("b.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n + 100; i++)
        if (i * (i - 1) / 2 == n)
        {
            cout << "YES";
            return 0;
        }
    cout << "NO";
    return 0;
}