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
pair < double, double > s[600000];

double solve(int a, int u, int t, int b)
{
    //cout << a << " " << u << " " << t << " " << b << endl;
    double l = 0.0, r = 1e12;
    int f = 0;
    while (f < 200)
    {
        f ++;
        double key = (l + r) / 2.0;
        double p = -2.0e9;
        double q = 2.0e9;
        for (int i = a; i <= u; i ++)
            p = max(p, s[i].first + s[i].second * key);
        for (int i = t; i <= b; i ++)
            q = min(q, s[i].first + s[i].second * key);
        if (p > q)
            r = key; else
            l = key;
    }
    return r;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%lf%lf", &s[i].first, &s[i].second);
    sort(s + 1, s + n + 1);

    double res = 1e12;

    int curl = 1;
    for (int i = 2; i <= n; i ++)
        if (s[i - 1].second > 0 && s[i].second < 0)
        {
            int curr = i;
            for (int j = i + 1; j <= n; j ++)
                if (s[j].second < 0) curr = j; else break;
            res = min(res, solve(curl, i - 1, i, curr));
            i = curr, curl = curr + 1;
        }
    if (res < -0.5 || res > 1e10)
        printf("-1\n"); else
        printf("%.12lf\n", res);
    return 0;
}