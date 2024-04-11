#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 500000 + 9, A = 1000000 + 9;

vector<int> divisors[A];
vector<int> pos[A];
int idx[A];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    vector<int> lge(n), rgt(n, n), llt(n), rlt(n);
    {
        stack<int> stk;
        for (int i = 0; i < n; ++i)
        {
            while (!stk.empty() && a[stk.top()] < a[i])
            {
                rgt[stk.top()] = i;
                stk.pop();
            }
            lge[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
    }
    {
        stack<int> stk;
        for (int i = 0; i < n; ++i)
        {
            while (!stk.empty() && a[stk.top()] >= a[i])
                stk.pop();
            llt[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
    }
    {
        stack<int> stk;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!stk.empty() && a[stk.top()] >= a[i])
                stk.pop();
            rlt[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (auto d : divisors[a[i]])
        {
            auto &p = pos[d];
            int t = idx[d];
            if (t > 0)
            {
                int l2 = p[t - 1];
                int l1 = max(lge[i], llt[l2]), r2 = min(rgt[i], rlt[l2]);
                if (l1 < l2 && i < r2)
                    ans += (LL)(l2 - l1) * (r2 - i);
            }
            if (t < p.size())
            {
                int r1 = p[t];
                int l1 = max({lge[i], llt[r1], t > 0 ? p[t - 1] : -1}), r2 = min(rgt[i], rlt[r1]);
                if (l1 < i && r1 < r2)
                    ans += (LL)(i - l1) * (r2 - r1);
            }
        }
        ++idx[a[i]];
    }
    cout << ans << '\n';
    for (auto x : a)
    {
        pos[x].clear();
        idx[x] = 0;
    }
}

void init()
{
    for (int i = 1; i < A; ++i)
    {
        for (int j = i; j < A; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    init();
    while (T--)
    {
        solve();
    }
}