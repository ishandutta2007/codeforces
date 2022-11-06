#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9, mod = 998244353;



void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1), ap(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ap[a[i]] = i;
    }
    vector<int> b(n + 1), bp(n + 1, -1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        if (b[i] != -1)
            bp[b[i]] = i;
    }
    LL ans = 1;
    set<int> st;
    int cur = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (cur < min(n, i + s))
        {
            ++cur;
            if (b[ap[cur]] == -1)
                st.insert(cur);
        }
        if (bp[i] != -1)
        {
            if (a[bp[i]] > i + s)
            {
                cout << "0\n";
                return;
            }
            int tmp = a[bp[i]];
            if (b[ap[i]] == -1)
            {
                st.erase(i);
                st.insert(tmp);
            }
            swap(a[ap[i]], a[bp[i]]);
            swap(ap[i], ap[tmp]);
        }
        else
        {
            ans = ans * st.size() % mod;
            int tmp = *st.begin();
            if (b[ap[i]] != -1)
            {
                st.erase(tmp);
                st.insert(i);
            }
            swap(a[ap[i]], a[ap[tmp]]);
            swap(ap[i], ap[tmp]);
        }
        if (b[ap[i]] == -1)
            st.erase(i);
    }
    cout << ans << '\n';
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