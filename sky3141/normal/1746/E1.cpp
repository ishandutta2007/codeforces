#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int N = 200000 + 9;
constexpr int can[] = {0b0000, 0b0001, 0b0010, 0b0100, 0b1000, 0b0101, 0b1001, 0b1010};

bool query(const vector<int> &vec)
{
    cout << "? " << vec.size();
    for (auto &x : vec)
    {
        cout << ' ' << x;
    }
    cout << endl;
    string res;
    cin >> res;
    return res == "YES";
}

void guess(int x)
{
    cout << "! " << x << endl;
    string res;
    cin >> res;
    if (res == ":)")
        exit(0);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n; ++i)
    {
        a[i - 1] = i;
    }
    while (a.size() > 8)
    {
        vector<int> t[16];
        for (int i = 0; i < a.size(); ++i)
        {
            t[i % 16].push_back(a[i]);
        }
        for (int i = a.size(); i < 16; ++i)
        {
            t[i].push_back(1);
        }
        vector<int> q[4];
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 16; ++j)
            {
                if (j & (1 << i))
                {
                    for (auto x : t[j])
                    {
                        q[i].push_back(x);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 4; ++i)
        {
            ans |= query(q[i]) << i;
        }
        a.clear();
        for (auto v : can)
        {
            for (auto x : t[ans ^ v])
            {
                a.push_back(x);
            }
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    while (a.size() > 3)
    {
        vector<int> t[4];
        for (int i = 0; i < a.size(); ++i)
        {
            t[i % 4].push_back(a[i]);
        }
        for (int i = a.size(); i < 4; ++i)
        {
            t[i].push_back(1);
        }
        vector<int> q[2];
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (j & (1 << i))
                {
                    for (auto x : t[j])
                    {
                        q[i].push_back(x);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 2; ++i)
        {
            ans |= query(q[i]) << i;
        }
        a.clear();
        for (auto v : {0, 1, 2})
        {
            for (auto x : t[ans ^ v])
            {
                a.push_back(x);
            }
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() == 3)
    {
        if (query({a[0]}) || query({a[0]}))
        {
            guess(a[0]);
            if (query({a[1]}))
                guess(a[1]);
            else
                guess(a[2]);
        }
        else
        {
            guess(a[1]);
            guess(a[2]);
        }
    }
    for (auto x : a)
    {
        guess(x);
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