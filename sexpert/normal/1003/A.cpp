#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    int x[105];
    memset(x, 0, sizeof(x));
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        x[a-1]++;
    }
    int res = 0;
    for(int i = 0; i < 100; i++)
    {
        res = max(res, x[i]);
    }
    cout << res;
}