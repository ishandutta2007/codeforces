#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <cstring>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

int a, b, c, d, e;
ld x;

ld get(int a, int h) {
    return (a * h + 0.0) / (2.0 * sqrtl(h * h + (a * a + 0.0) / 4.0));
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> x;
    for (int i = 1; i < 11; i++)
    for (int j = 1; j < 11; j++)
    if (fabsl(get(i, j) - x) < 0.0001) {
        cout << i << " " << j << "\n";
        return 0;
    }
    return 0;
}