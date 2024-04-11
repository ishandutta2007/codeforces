#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mx = -1;
    int a[100010], n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        if(a[i] > mx + 1)
        {
            cout << i + 1 << endl;
            return 0;
        }
        mx = max(mx, a[i]);
    }
    cout << -1 << endl;
}