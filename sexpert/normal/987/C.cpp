#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int sizes[3005];
    int costs[3005];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> sizes[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> costs[i];
    }
    int ans = 1e9;
    for(int i = 1; i < n - 1; i++)
    {
        int tot = costs[i], low = 1e9, hi = 1e9;
        bool possible = true, found;
        found = false;
        for(int j = 0; j < i; j++)
        {
            if(sizes[j] < sizes[i])
            {
                found = true;
                low = min(low, costs[j]);
            }
        }
        if(!found) possible = false;
        found = false;
        for(int j = i + 1; j < n; j++)
        {
            if(sizes[j] > sizes[i])
            {
                found = true;
                hi = min(hi, costs[j]);
            }
        }
        if(!found) possible = false;
        if(possible)
        {
            tot += (low + hi);
            ans = min(ans, tot);
        }
    }
    if(ans == 1e9) cout << -1;
    else cout << ans;
}