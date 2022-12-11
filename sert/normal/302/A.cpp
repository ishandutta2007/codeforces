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
typedef long double ld;
const ll N = 1e6 + 5;

ll a[N];
ll n, k, m, ed, med, l, r;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    fr(i, n) {
        cin >> k;
        if (k == 1) ed++;
        else med++;
    }
    fr(i, m) {
        cin >> l >> r;
        if ((r - l) % 2 == 1 && min(med, ed) * 2 + l > r)
            cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}