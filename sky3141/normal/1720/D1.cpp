#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 300000 + 9, MAXLOG = 30;

struct Node
{
    int mx[2];
    Node* ch[2];
} pool[MAXN * (MAXLOG + 1)], *root, *alloc = pool;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    int ans = 0;
    root = alloc++;
    *root = {};
    for (int i = 0; i < n; ++i)
    {
        int x = a[i] ^ i;
        int curans = 1;
        Node *curnode = root;
        for (int k = 30; k >= 0; --k)
        {
            int cch = (x >> k) & 1;
            if (curnode->ch[!cch])
                curans = max(curans, 1 + curnode->ch[!cch]->mx[(i >> k) & 1]);
            if (!curnode->ch[cch])
                break;
            curnode = curnode->ch[cch];
        }
        ans = max(ans, curans);
        curnode = root;
        for (int k = 30; k >= 0; --k)
        {
            int cch = (x >> k) & 1;
            if (!curnode->ch[cch])
            {
                curnode->ch[cch] = alloc++;
                *curnode->ch[cch] = {};
            }
            curnode->ch[cch]->mx[(a[i] >> k) & 1] = max(curnode->ch[cch]->mx[(a[i] >> k) & 1], curans);
            curnode = curnode->ch[cch];
        }
    }
    cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}