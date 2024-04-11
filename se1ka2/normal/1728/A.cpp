#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[200005];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > a[l])
            {
                l = i;
            }
        }
        cout << l + 1 << endl;
    }
}