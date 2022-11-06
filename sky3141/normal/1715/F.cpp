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
using pdd = pair<double, double>;

constexpr int MAXN = 200000 + 9;

double query(const vector<pdd> &vec)
{
    cout << "? " << vec.size() << '\n';
    for (auto &p : vec)
    {
        cout << p.first << ' ' << p.second << '\n';
    }
    cout.flush();
    double res;
    cin >> res;
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    double ansx, ansy;

    {
        vector<pdd> q{{0, 0}};
        for (int i = 0; i < m; ++i)
        {
            q.push_back({n, i + 0.5});
            q.push_back({0, i + 1});
        }
        ansx = n - 0.5 - query(q) * n;
    }

    {
        vector<pdd> q{{0, 0}};
        for (int i = 0; i < n; ++i)
        {
            q.push_back({i + 0.5, m});
            q.push_back({i + 1, 0});
        }
        ansy = m - 0.5 - query(q) * m;
    }

    cout << "! " << ansx << ' ' << ansy << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout.setf(ios::fixed);
    cout.precision(12);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    
    return 0;
}