#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

using LL = long long;

struct Point
{
    int x, y;
};

// Point a, b, c;
Point p[3];
vector<vector<int>> vec;

LL mdis(const Point &a, const Point &b)
{
    return (LL)abs(a.x - b.x) + abs(a.y - b.y);
}

void con(const Point &a, const Point &b)
{
    int mn = min(a.x, b.x), mx = max(a.x, b.x);
    if (mn != mx)
        vec.push_back({mn, a.y, mx, a.y});
    mn = min(a.y, b.y), mx = max(a.y, b.y);
    if (mn != mx)
        vec.push_back({b.x, mn, b.x, mx});
}

// void line(const Point &a, const Point &b, const Point &c)
// {
//     con(a, b);
//     con(b, c);
//     cout << vec.size() << '\n';
//     for (auto &v : vec)
//     {
//         for (auto &x : v)
//         {
//             cout << x << ' ';
//         }
//         cout << '\n';
//     }
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; ++i)
    {
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p + 3, [](const auto &a, const auto &b){ return a.x < b.x; });

    con(p[0], p[1]);
    int mx = max(p[0].y, p[1].y), mn = min(p[0].y, p[1].y);
    int ty = p[2].y;
    if (ty > mx)
        ty = mx;
    if (ty < mn)
        ty = mn;
    con(Point{p[1].x, ty}, p[2]);
    
    cout << vec.size() << '\n';
    for (auto &v : vec)
    {
        for (auto &x : v)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }


    // cin >> a.x >> a.y;
    // cin >> b.x >> b.y;
    // cin >> c.x >> c.y;

    // LL t1 = mdis(a, b), t2 = mdis(a, c), t3 = mdis(b, c);
    // if (t1 > t2 && t1 > t3)
    // {
    //     line(a, c, b);
    // }
    // else if (t2 > t3)
    // {
    //     line(a, b, c);
    // }
    // else
    // {
    //     line(b, a, c);
    // }

    return 0;
}