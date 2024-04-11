#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n; 
    vector<int> m(n);
    for (auto& x : m)
        cin >> x;
    vector<int> le(n + 1);
    for (int i = 0; i < n; ++i)
        le[i + 1] = max(le[i], m[i] + 1);
    vector<int> le1 = le;
    vector<int> ri(n + 1, -1e9);
    for (int i = n - 1; i >= 0; --i)
        ri[i] = max(ri[i + 1], m[i] + 1 - i);
    for (int i = 0; i < n; ++i)
        le[i] = max(le[i], ri[i + 1] + i);
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
            assert(le[i] <= 1);
        le[i] = max(1, le[i]);
        le[i] = max(le[i], le1[i + 1]);
        ans += le[i] - m[i] - 1;
    }
    cout << ans << '\n';
}