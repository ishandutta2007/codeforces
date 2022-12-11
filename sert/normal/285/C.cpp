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

ll a[N];
ll n, m, ans;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    fr(i, n)
        ans += fabs(i + 1 - a[i]);
    cout << ans;


    return 0;
}