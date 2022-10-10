#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, r, a[1010];
    cin >> n >> r;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int maxGrabbed = 1 - r, ans = 0;
    while(maxGrabbed + r <= n)
    {
        int ptr = min(maxGrabbed + 2*r - 1, n);
        int bnd = max(maxGrabbed, 0);
        for(int i = ptr; i > bnd; i--)
        {
            if(a[i] == 1)
            {
                maxGrabbed = i;
                ans++;
                break;
            }
            if(i == bnd + 1)
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}