#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[200005], b[200005];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int l[200005];
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            l[i] = lower_bound(b, b + n, a[i]) - b;
            if (l[i] == i)
            {
                v.push_back(i);
            }
        }
        v.push_back(n);
        int r[200005];
        for (int i = 0; i < n; i++)
        {
            r[i] = *upper_bound(v.begin(), v.end(), i);
        }
        for (int i = 0; i < n; i++)
        {
            cout << b[l[i]] - a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << b[r[i] - 1] - a[i] << " ";
        }
        cout << endl;
    }
}