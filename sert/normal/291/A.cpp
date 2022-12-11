#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

#define fr(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 7;
const ll M = 1e3 + 3;
const ll md = 1e9+7;

using namespace std;

ll a[N];
ll n, ans;


int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    fr(i, n) cin >> a[i];
    sort(a, a + n);
    for(int i = 2; i < n; i++)
        if (a[i] == a[i - 1] && a[i] == a[i - 2] && a[i] != 0){
            cout << "-1";
            return 0;
        }

    for(int i = 1; i < n; i++)
        if (a[i] == a[i - 1] && a[i] != 0)
            ans++;

    cout << ans;

    return 0;
}