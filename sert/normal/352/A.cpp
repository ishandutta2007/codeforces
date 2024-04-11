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
const ll N = 103;

ll n, k, sum, pt, zp = 0;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n) {
        cin >> k;
        if (k == 5)
            pt++;
        if (k == 0)
            zp++;
    }
    if (zp == 0) {
        cout << -1;
        return 0;
    }
    if (pt < 9) {
        cout << 0;
        return 0;
    }
    fr(i, 9 * (pt / 9))
        cout << "5";
    fr(i, zp) cout << 0;
    return 0;
}