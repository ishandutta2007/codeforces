#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[200005];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l[200005], r[200005];
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || a[i] <= a[i - 1])
        {
            l[i] = i;
        }
        else
        {
            l[i] = l[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1 || a[i] >= a[i + 1])
        {
            r[i] = i;
        }
        else
        {
            r[i] = r[i + 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, r[i] - i + 1);
        ans = max(ans, i - l[i] + 1);
        if(i > 0 && i < n - 1)
        {
            if (a[i - 1] < a[i + 1])
            {
                ans = max(ans, r[i + 1] - l[i - 1]);
            }
        }
    }
    cout << ans << endl;
}