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

ll m, l, r, a[10][10], t, sum;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    fr(i, 3)
        fr(j, 3)
            cin >> a[i][j];
    a[1][1] = 1;
    sum = a[1][0] + a[1][1] + a[1][2];
    a[0][0] = sum - a[0][1] - a[0][2];
    a[2][2] = sum - a[2][1] - a[2][0];
    ll mn = min(a[0][0], min(a[1][1], a[2][2]));
    mn = (a[2][0] + a[2][1] - a[0][0] - a[1][1]);
    mn /= 2;
    fr(i, 3)
        a[i][i] += mn;
    fr(i, 3) {
        fr(j, 3)
            cout << a[i][j] << " ";
        cout << "\n";

    }



    return 0;
}