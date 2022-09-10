#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, res, t[57];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];

        if(t[i]>0 && t[i]>=t[k])
        {
            res++;
        }
    }

    cout << res;
}