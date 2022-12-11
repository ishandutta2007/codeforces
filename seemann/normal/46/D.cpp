#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))
#define ll long long
//define _in_s(a, b) (((a) < h)&&((a) >= 0)&&((b) < w)&&((b) >= 0))
const int INF = 1000000000;

map<int, int> c;
set <int> sc;
int nm[101];

int main()
{

    int l, b, f;
    cin >> l >> b >> f;
    c[-b] = 0;
    sc.insert(-b);
    c[l + f] = 0;
    sc.insert(l + f);
    int n;
    cin >> n;
    clr(nm);

    FOR(i, n)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            bool ind = false;
            for(set<int>::iterator it = sc.begin(); it != sc.end(); it++)
            {

                set<int>::iterator w = it;
                w++;
                if (w == sc.end()) break;

                if (y + b + f <= *w - *it - c[*it])
                {
                    int p = *it + c[*it] + b;
                    nm[i] = p;
                    c[p] = y;
                    sc.insert(p);
                    cout << p << '\n';
                    ind = true;
                    break;
                }
            }
            if (!ind) cout << "-1\n";
        }
        else
        {
            y--;
            c.erase(nm[y]);
            sc.erase(nm[y]);
        }
    }


    return 0;
}