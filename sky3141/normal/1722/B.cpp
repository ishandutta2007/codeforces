#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;



void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (auto &c : a)
    {
        if (c == 'B')
            c = 'G';
    }
    for (auto &c : b)
    {
        if (c == 'B')
            c = 'G';
    }
    cout << (a == b ? "yes" : "no") << '\n';
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
    
    return 0;
}