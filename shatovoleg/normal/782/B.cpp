#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using pdb = pair<ld, bool>;
#define eps 0.000000001

bool will_meet(vector<ld> x, vector<ld> v, ld time)
{
    vector<pdb> dots;
    int n = x.size();
    for (int i = 0; i < n; ++i)
    {
        dots.push_back({x[i] - v[i] * time, true});
        dots.push_back({x[i] + v[i] * time, false});
    }
    sort(dots.begin(), dots.end(), [](pdb a, pdb b)
    {
        if (fabs(a.first - b.first) < eps)
        {
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    int cnt = 0, mx = 0;
    for (auto x : dots)
    {
        if (x.second)
            ++cnt;
        else
            --cnt;
        if (cnt > mx)
            mx = cnt;
    }
    return mx >= n;
}

int main()
{
    int n;
    cin >> n;
    vector<ld> x(n), v(n);
    for (auto &b : x)
        cin >> b;
    for (auto &b : v)
        cin >> b;
    ld l = 0, r = 10000000000;
    for (int i = 0; i < 100; ++i)
    {
        ld c = (r + l) / 2;
        if (will_meet(x, v, c))
            r = c;
        else
            l = c;
    }
    cout << fixed << setprecision(7) << r << endl;
}