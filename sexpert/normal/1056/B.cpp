#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    long long ct[1005];
    cin >> n >> m;
    for(int i = 1; i < m; i++)
    {
        ct[i] = (n + m - i)/m;
    }
    ct[0] = n/m;
    long long ans = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if((i*i + j*j)%m == 0)
            {
                ans += ct[i]*ct[j];
            }
        }
    }
    cout << ans << endl;
}