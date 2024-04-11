#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        string a, b;
        cin >> n >> m >> a >> b;
        bool f = true;
        if(m > n)
        {
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < m - 1; i++)
        {
            if(a[n - 1 - i] != b[m - 1 - i])
            {
                f = false;
            }
        }
        bool g = false;
        for(int i = m - 1; i < n; i++)
        {
            if(a[n - 1 - i] == b[0])
            {
                g = true;
            }
        }
        if(f && g)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}