#include <bits/stdc++.h>
#define inf 1000000;
using namespace std;

int n, res = inf;

int t[107];

int res0[107];
int resS[107];
int resC[107];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> t[i];

        res0[i] = inf;
        resS[i] = inf;
        resC[i] = inf;
    }

    for(int i = 1; i <= n; ++i)
    {
        res0[i] = min(res0[i], res0[i-1]+1);
        res0[i] = min(res0[i], resS[i-1]+1);
        res0[i] = min(res0[i], resC[i-1]+1);

        if(t[i]==1 || t[i]==3)
        {
            resC[i] = min(resC[i], res0[i-1]);
            resC[i] = min(resC[i], resS[i-1]);
        }

        if(t[i]==2 || t[i]==3)
        {
            resS[i] = min(resS[i], res0[i-1]);
            resS[i] = min(resS[i], resC[i-1]);
        }
    }

    res = min(res, res0[n]);
    res = min(res, resC[n]);
    res = min(res, resS[n]);

    cout << res;
}