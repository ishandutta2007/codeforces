#include <bits/stdc++.h>

#ifndef LOCAL
#define stderr lorem_ipsum
#define cerr dolor_sit_amet
#endif

#define sz(x) ((int)((x).size()))
#define mp(x,y) make_pair((x), (y))
#define allIter(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits < double > ::infinity();
const double EPS = 1e-9;
const int DX[] = {1, 0, -1,  0, 1, -1,  1, -1};
const int DY[] = {0, 1,  0, -1, 1, -1, -1,  1};

int main()
{
    ios::sync_with_stdio(false);

    ll ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int t = 0;
    while (true)
    {
        if (t == 0)
        {
            if (bx > ax)
            {
                if (ay != 0 && (bx != ax || by != ay - 1))
                    --ay;
                else if (ax != 0 && (by != ay || bx != ax - 1))
                    --ax;
            } else {
                if (ax != 0 && (by != ay || bx != ax - 1))
                    --ax;
                else if (ay != 0 && (bx != ax || by != ay - 1))
                    --ay;
            }
            if (ax == 0 && ay == 0)
            {
                cout << "Polycarp\n";
                return 0;
            }
        } else {
            if (bx == 0)
            {
                if (ax != bx || ay != by - 1)
                    --by;
            } else if (by == 0)
            {
                if (ay != by || ax != bx - 1)
                    --bx;
            } else if (ax != bx - 1 || ay != by - 1)
            {
                --bx;
                --by;
            }

            if (bx == 0 && by == 0)
            {
                cout << "Vasiliy\n";
                return 0;
            }
        }
        t = 1 - t;
    }

    return 0;
}