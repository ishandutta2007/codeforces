#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[300000 + 10];
int main()
{
    int n, i;cin >> n;
    for(i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    cout << a[(n + 1) / 2];
}