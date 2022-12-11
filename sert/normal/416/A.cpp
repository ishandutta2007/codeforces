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

ll a[N];
ll n, k, p, t, h, l, r;
char ch;
string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    l = -1900000000;
    r = 1900000000;
    for (int i = 0; i < n; i++) {
        cin >> s >> k >> ch;
        if ((s == ">=" && ch == 'Y') || (s == "<" && ch == 'N')) l = max(l, k);
        if ((s == ">=" && ch != 'Y') || (s == "<" && ch != 'N')) r = min(k - 1, r);
        if ((s == ">" && ch == 'Y') || (s == "<=" && ch == 'N')) l = max(l, k + 1);
        if ((s == ">" && ch != 'Y') || (s == "<=" && ch != 'N')) r = min(r, k);
        //cerr << l << " " << r << "\n";
    }
    if (l > r) cout << "Impossible\n";
    else cout << (l + r) / 2 << "\n";
    return 0;
}