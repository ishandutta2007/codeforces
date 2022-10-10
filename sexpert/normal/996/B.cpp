#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    vector<int> a, f;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++)
    {
        f.push_back(n*((a[i] - i + n - 1)/n) + i);
    }
    int res = 10e9 + 5, ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(res > f[i])
        {
            res = f[i];
            ans = i + 1;
        }
    }
    cout << ans;
}