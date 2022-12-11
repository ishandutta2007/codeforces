#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

int n, m, k, a[1000], sum;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    for(int i = 0; i < n; i++)
        sum += a[i] - 1;

    if (sum + k < m){
        cout << "-1";
        return 0;
    }

    sum = k;
    int j = n - 1;

    while(sum < m)
        sum += a[j--] - 1;

    cout << n - j - 1;

    return 0;
}