#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using pii = pair<int, int>;

constexpr int N = 200000 + 9, INF = 1000000000;

struct Seg
{
    int l, r;
    int id;
};

int n;
vector<Seg> seg[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        seg[i].clear();
    }
    for (int i = 0; i < n; ++i)
    {
        int l, r, c;
        cin >> l >> r >> c;
        seg[c].push_back({l, r, i});
    }
    vector<int> ans(n, INF);
    set<pii> st;
    for (int i = 1; i <= n; ++i)
    {
        for (auto &[l, r, id] : seg[i])
        {
            auto it = st.lower_bound({r, 0});
            if (it != st.end())
            {
                if (it->second == 0) // l
                    ans[id] = min(ans[id], it->first - r);
                else
                    ans[id] = 0;
            }
            it = st.lower_bound({l, 0});
            if (it != st.end() && it->first <= r)
                ans[id] = 0;
            if (it != st.begin())
            {
                --it;
                if (it->second == 0) // l
                    ans[id] = 0;
                else
                    ans[id] = min(ans[id], l - it->first);
            }
        }
        for (auto &[l, r, id] : seg[i])
        {
            while (true)
            {
                auto it = st.lower_bound({l, 0});
                if (it == st.end() || it->first > r)
                    break;
                st.erase(it);
            }
            auto it = st.lower_bound({l, 0});
            if (it == st.begin() || prev(it)->second == 1)
                st.insert({l, 0});
            it = st.lower_bound({r, 1});
            if (it == st.end() || it->second == 0)
                st.insert({r, 1});
        }
    }
    st.clear();
    for (int i = n; i >= 1; --i)
    {
        for (auto &[l, r, id] : seg[i])
        {
            auto it = st.lower_bound({r, 0});
            if (it != st.end())
            {
                if (it->second == 0) // l
                    ans[id] = min(ans[id], it->first - r);
                else
                    ans[id] = 0;
            }
            it = st.lower_bound({l, 0});
            if (it != st.end() && it->first <= r)
                ans[id] = 0;
            if (it != st.begin())
            {
                --it;
                if (it->second == 0) // l
                    ans[id] = 0;
                else
                    ans[id] = min(ans[id], l - it->first);
            }
        }
        for (auto &[l, r, id] : seg[i])
        {
            while (true)
            {
                auto it = st.lower_bound({l, 0});
                if (it == st.end() || it->first > r)
                    break;
                st.erase(it);
            }
            auto it = st.lower_bound({l, 0});
            if (it == st.begin() || prev(it)->second == 1)
                st.insert({l, 0});
            it = st.lower_bound({r, 1});
            if (it == st.end() || it->second == 0)
                st.insert({r, 1});
        }
    }
    for (auto x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
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