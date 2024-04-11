#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll a[200005];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll s = 0;
        bool f = true;
        bool g = false;
        for(int i = 0; i < n; i++)
        {
            if(g && a[i])
            {
                f = false;
            }
            s += a[i];
            if(s < 0)
            {
                f = false;
            }
            if(s == 0)
            {
                g = true;
            }
        }
        if(s)
        {
            f = false;
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