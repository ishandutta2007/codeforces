#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n;
int a[200000], b[200000], d[200000];
int rv[200000];
set < pair < int, int > > S;
map < int, int > MP;

vector < int > V[200000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), b[i] = a[i];

    sort(b + 1, b + n + 1);

    MP[b[1]] = 1; rv[1] = b[1];
    int m = 1;
    for (int i = 2; i <= n; i ++)
        if (b[i] > b[i - 1])
            m ++, MP[b[i]] = m, rv[m] = b[i];

    for (int i = 1; i <= n; i ++)
        a[i] = MP[a[i]], V[a[i]].push_back(i);

    for (int i = 1; i <= n; i ++)
    {
        d[i] = 1000000;
        for (int j = V[a[i]].size() - 1; j >= 0; j --)
        {
            if (V[a[i]][j] >= i) continue;
            bool good = true;
            if (i + i - V[a[i]][j] - 1 > n) continue;
            int v = V[a[i]][j];
            for (int k = v, l = i - 1; k < i && l >= v && k < l; k ++, l --)
            {
                if (a[k] != a[i + k - v])
                {
                    good = false;
                    break;
                }
                if (a[l] != a[i + l - v])
                {
                    good = false;
                    break;
                }
            }
            if (good)
            {
                d[i] = min(d[i], i - v);
                break;
            }
        }

        if (d[i] != 1000000)
            S.insert(make_pair(d[i], i));
    }

    int v = 1;
    while (!S.empty())
    {
        int x = S.begin()->second; S.erase(S.begin());
        if (x - d[x] < v) continue;
        v = x;
    }
    printf("%d\n", n - v + 1);
    for (int i = v; i <= n; i ++)
        printf("%d ", rv[a[i]]);
    printf("\n");
    return 0;
}