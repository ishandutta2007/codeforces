#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
long long INF = 1e12;

int ans[10000], a[10000], sum[10000];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 10; j++)
            sum[j] = 0;
        int mx = 0, pos = 0;
        for (int j = i; j < n; j++)
        {
            sum[a[j]]++;
            if (sum[a[j]] > mx || (sum[a[j]] == mx && pos > a[j]))
            {
                mx = sum[a[j]];
                pos = a[j];
            }
            ans[pos]++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ' ;
    return 0;
}