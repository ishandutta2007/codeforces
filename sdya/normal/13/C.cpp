#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int n;
long long a[6000];
long long d1[6000], d2[6000];
long long num[6000];

bool comp(long long p, long long q) {return (a[p] < a[q]);}
long long ab(long long x) {return (x > 0LL ? x : -x);}

long long mn(long long a, long long b) {return (a < b ? a : b);}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int p; scanf("%d", &p);
        a[i] = p;
        num[i] = i;
    }

    sort(num + 1, num + n + 1, comp);
    d1[1] = ab(a[1] - a[num[1]]);
    for (int i = 2; i <= n; i ++) d1[i] = mn(d1[i - 1], ab(a[1] - a[num[i]]));

    for (int i = 2; i <= n; i ++)
    {
        d2[1] = d1[1] + ab(a[i] - a[num[1]]);
        for (int j = 2; j <= n; j ++)
            d2[j] = mn(d2[j - 1], d1[j] + ab(a[i] - a[num[j]]));

        for (int j = 1; j <= n; j ++) d1[j] = d2[j];
    }

    long long res = d1[1];
    for (int i = 1; i <= n; i ++) res = mn(res, d1[i]);
    cout << res << endl;
    return 0;
}