#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[51];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        int s = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> a[j];
        }
        sort(a, a + m);
        for (int j = 0; j < m-1; j++)
        {

            if (a[j] == a[j + 1])
            {
                s++;
            }
        }

        if (s % 2 == 0)
        {
            cout << m - s << "\n";
        }
        else
            cout << m - s - 1 << "\n";
    }
    return 0;
}