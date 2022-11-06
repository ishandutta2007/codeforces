#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    string s;
    cin >> s;
    bool ok = s.back() == 'B';
    int sum = 0;
    for (auto &c : s)
    {
        if (c == 'A')
            ++sum;
        else
            --sum;
        if (sum < 0)
            ok = false;
    }
    cout << (ok ? "Yes\n" : "No\n");
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