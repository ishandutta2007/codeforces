#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    set<LL> st;
    map<LL, LL> mp;
    while (n--)
    {
        char op;
        LL x;
        cin >> op >> x;
        if (op == '+')
        {
            st.insert(x);
        }
        else // ?
        {
            auto it = mp.insert({x, x}).first;
            while (st.contains(it->second))
            {
                it->second += x;
            }
            cout << it->second << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}