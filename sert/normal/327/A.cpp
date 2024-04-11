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

int n, k, ans = -100, ke, p, t;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n) {
        cin >> k;
        if (k == 1) ke++;
        t += (1 - k) * 2 - 1;
        ans = max(ans, t - p);
        p = min(t, p);
    }
    cout << ke + ans;
    return 0;
}