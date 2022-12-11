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

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> a >> b >> c >> d >> e;
    c = c / 2;
    d = d / 7;
    e = e / 4;
    cout << min(a, min(b, min(c, min(d, e))));
    return 0;
}