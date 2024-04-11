#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++mp[x];
    }
    vector<int> vec;
    for (auto &[x, cnt] : mp)
    {
        if (cnt >= k)
            vec.push_back(x);
    }
    int mxlen = -1;
    int al, ar;
    for (int i = 0; i < vec.size(); ++i)
    {
        int l = vec[i];
        while (i + 1 < vec.size() && vec[i + 1] == vec[i] + 1)
        {
            ++i;
        }
        int r = vec[i];
        if (r - l > mxlen)
        {
            mxlen = r - l;
            al = l; ar = r;
        }
    }
    if (mxlen != -1)
        cout << al << ' ' << ar << '\n';
    else
        cout << "-1\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}