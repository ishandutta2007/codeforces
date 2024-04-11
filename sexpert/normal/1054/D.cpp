#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int a[200005], ls[200005], partial[200005];
    long long n, k;
    for(int i = 0; i < 200005; i++)
    {
        ls[i] = INF;
    }
    cin >> n >> k;
    int x = (1 << k) - 1;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    partial[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        partial[i] = partial[i - 1] ^ a[i];
    }
    long long ans = n*(n + 1ll)/2ll;
    map<int, int> ct;
    for(int i = 0; i <= n; i++)
    {
        ct[min(partial[i], x - partial[i])]++;
    }
    for(auto p : ct)
    {
        int m = p.second;
        if(m % 2 == 0)
        {
            long long b = m/2;
            ans -= b*(b - 1);
        }
        else
        {
            long long b = (m - 1)/2;
            ans -= b*b;
        }
    }
    cout << ans << endl;
}