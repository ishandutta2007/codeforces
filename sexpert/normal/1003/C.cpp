#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n, k, a;
    double psums[5005];
    psums[0] = 0.0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        psums[i + 1] = psums[i] + a;
    }
    double res = 0.0;
    for(int j = k; j <= n; j++)
    {
        for(int i = 0; i + j <= n; i++)
        {
            res = max(res, (double)(psums[i + j] - psums[i])/((double)j));
        }
    }
    cout << fixed << setprecision(20) << res;
}