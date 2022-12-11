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

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef double ld;
const ll N = 1e6+5;

int n, wp, np, w, nz;
bool sr;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n) {
        cin >> w >> nz;
        np += nz;
        wp += w;
        if (nz % 2 != w % 2) sr = true;
    }
    if (np % 2 == 0 && wp % 2 == 0) cout << 0;
    if ((np + wp) % 2 == 1) cout << -1;
    if (np % 2 == 1 && wp % 2 == 1)
        if (sr) cout << 1;
        else cout << -1;





    return 0;
}