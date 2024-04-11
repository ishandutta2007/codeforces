#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n, h, p, k, a[1000000], ans, sum, mn = 1000000;

int main()
{

       //freopen("a.in", "r", stdin);
   //freopen("a.out", "w", stdout);
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> h;
        mn = min(mn, h);
    }
    h = mn;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    h += 2;
    p = n - h;

    while(p >= 0){
        sum += a[p] + a[p + 1];
        p -= h;
    }
    if (p == -1)
        sum += a[0];

    for(int i = 0; i < n; i++)
        ans += a[i];

    cout << ans - sum;

    return 0;
}