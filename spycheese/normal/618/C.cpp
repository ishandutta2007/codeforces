#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 100179;

struct Vec2
{
    ll x, y;

    Vec2 operator - (const Vec2 & b) const
    {
        return {x - b.x, y - b.y};
    }
};

ll dot(const Vec2 & a, const Vec2 & b)
{
    return a.x*b.x + a.y*b.y;
}

ll cross(const Vec2 & a, const Vec2 & b)
{
    return a.x*b.y - a.y*b.x;
}

int n;
Vec2 p[N];
int t1, t2, t3;

bool isInside(const Vec2 & a)
{
    Vec2 b1 = p[t1];
    Vec2 b2 = p[t2];
    Vec2 b3 = p[t3];

    ll area = abs(cross(b1, b2) + cross(b2, b3) + cross(b3, b1));
    ll area1 = abs(cross(b1-a, b2-a)) + abs(cross(b2-a, b3-a)) + abs(cross(b3-a, b1-a));

    return area == area1;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;
    t1 = 0;
    t2 = 1;

    for (int i = 2; i < n; ++i)
    {
        Vec2 v1 = p[1] - p[0];
        Vec2 v2 = p[i] - p[0];
        if (v1.x*v2.y != v1.y*v2.x)
        {
            t3 = i;
            break;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (i == t1 || i == t2 || i == t3)
            continue;
        if (isInside(p[i]))
        {
            Vec2 v1 = p[t2] - p[t1];
            Vec2 v2 = p[i] - p[t1];
            if (v1.x*v2.y == v1.y*v2.x)
                t1 = i;
            else {
                Vec2 v1 = p[t3] - p[t2];
                Vec2 v2 = p[i] - p[t2];
                if (v1.x*v2.y == v1.y*v2.x)
                    t2 = i;
                else
                    t3 = i;
            }
        }
    }

    cout << t1 + 1 << " " << t2 + 1 << " " << t3 + 1 << "\n";

    return 0;
}