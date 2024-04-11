#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int n, x0;
int a[200], b[200];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> x0;
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d%d", &a[i], &b[i]);
        if (a[i] > b[i]) swap(a[i], b[i]);
    }

    int best = 1000000;
    for (int i = 0; i <= 1000; i ++)
    {
        bool good = true;
        for (int j = 1; j <= n; j ++)
            if (a[j] > i || b[j] < i) good = false;
        if (good) best = min(best, abs(i - x0));
    }
    if (best == 1000000) best = -1;
    cout << best << endl;
    return 0;
}