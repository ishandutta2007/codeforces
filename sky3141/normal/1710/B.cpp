#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

using LL = long long;

constexpr int MAXN = 200000 + 9;
constexpr LL INF = 1000000000000000000;

int n, m;
LL a[MAXN];
LL ml[MAXN];
LL mr[MAXN];
int ans[MAXN];

struct Rain
{
    int x, p, id;
    bool operator<(const Rain &rhs) const
    {
        return x < rhs.x;
    }
};

void solve()
{
    cin >> n >> m;
    fill(a, a + n + 1, 0);
    vector<Rain> vec;
    for (int i = 0; i < n; ++i)
    {
        int x, p;
        cin >> x >> p;
        vec.push_back({x, p, i});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; ++i)
    {
        a[i] -= vec[i].p;
        a[i] -= m;
    }
    {
        priority_queue<int, vector<int>, greater<int>> tq;
        LL sum = 0;
        for (int i = 0; i < vec.size(); ++i)
        {
            tq.push(vec[i].x + vec[i].p);
            sum += vec[i].x + vec[i].p;
            while (!tq.empty() && tq.top() < vec[i].x)
            {
                sum -= tq.top();
                tq.pop();
            }
            a[i] += sum - (vec[i].x * tq.size());
        }
    }
    // reverse(vec.begin(), vec.end());
    {
        priority_queue<int> tq;
        LL sum = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            tq.push(vec[i].x - vec[i].p);
            sum += vec[i].x - vec[i].p;
            while (!tq.empty() && tq.top() > vec[i].x)
            {
                sum -= tq.top();
                tq.pop();
            }
            a[i] += (vec[i].x * tq.size()) - sum;
        }
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    LL mx = -INF;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > 0)
        {
            mx = max(mx, a[i] - vec[i].x);
        }
        ml[i] = mx;
    }
    mx = -INF;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] > 0)
        {
            mx = max(mx, a[i] + vec[i].x);
        }
        mr[i] = mx;
    }
    for (int i = 0; i < n; ++i)
    {
        if (vec[i].p + vec[i].x >= mr[i] && vec[i].p - vec[i].x >= ml[i])
        {
            ans[vec[i].id] = 1;
        }
        else
        {
            ans[vec[i].id] = 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i];
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}