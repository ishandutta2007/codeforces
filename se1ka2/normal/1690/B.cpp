#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[200005], b[200005];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int d = 0;
        for(int i = 0; i < n; i++)
        {
            d = max(d, a[i] - b[i]);
        }
        bool f = true;
        for(int i = 0; i < n; i++)
        {
            if(b[i] && a[i] - b[i] < d)
            {
                f = false;
            }
        }
        if(f)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}