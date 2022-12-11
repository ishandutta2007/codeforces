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

ll m, l, r, a[N], t, sum;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> m;
    fr(i, m) { cin >> a[i]; sum += a[i];}
    cin >> l >> r;

    fr(i, m - 1) {
        t += a[i];
        //cerr << i << " " << t << "\n";
        if (t >= l && t <= r && sum - t <= r && sum - t >= l) {
            cout << i + 2;
            return 0;
        }
    }
    cout << 0;



    return 0;
}