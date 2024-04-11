#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXM = 2.1e6;

int N;
ll vv[MAXM];
vector <int> v;

bool bad (int a, int b, int c)
{
    return ((b - a) * (vv[c] - vv[b]) - (c - b) * (vv[b] - vv[a]) <= 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < MAXM; i++)
        vv[i] = 2e12;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll x, y;
        cin >> x >> y;
        y -= (x * x);
        x += 1000000;
        vv[x] = min (vv[x], -y);
    }

    for (int i = 0; i < MAXM; i++)
    {
        if (vv[i] > 1.9e12)
            continue;

        v.push_back(i);
        while (v.size() >= 3)
        {
            int x = (int) v.size() - 3;
            int a = v[x], b = v[x+1], c = v[x+2];
            if (bad (a, b, c))
            {
                v[x+1] = c;
                v.pop_back();
            }
            else
                break;
        }
    }
    cout << v.size() - 1 << "\n";
}