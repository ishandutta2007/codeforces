#include <bits/stdc++.h>
using namespace std;

int t[307];

int n, k, res;

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    if(t[k])
    {
        res++;
    }

    int l = k-1;
    int r = k+1;

    while(l>0 && r<n+1)
    {
        if(l>0 && r<n+1)
        {
            if(t[l] && t[r])
            {
                res += 2;
            }
        }

        l--;
        r++;

    }

    if(l==0)
    {
        for(;r<=n; r++)
        {
            res += t[r];
        }
    }

    if(r==n+1)
    {
        for(;l>=1; l--)
        {
            res += t[l];
        }
    }

    cout << res;
}