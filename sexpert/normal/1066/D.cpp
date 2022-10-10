#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, m, k, a[MAXN + 5];

bool valid(int start)
{
    int used = 1, cap = 0;
    for(int i = start; i < n; i++)
    {
        int wt = a[i];
        if(cap + wt <= k)
        {
            cap += wt;
            continue;
        }
        used++;
        cap = wt;
    }
    return (used <= m);
}

int bs()
{
    int low = 0, high = n - 1;
    while(low < high)
    {
        int mid = (low + high)/2;
        if(valid(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << n - bs() << endl;
}