#include <algorithm>
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
        int a[100005];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if(n % 2)
        {
            cout << "NO" << endl;
            continue;
        }
        sort(a, a + n);
        int b[100005];
        for(int i = 0; i < n / 2; i++)
        {
            b[i * 2] = a[i];
            b[i * 2 + 1] = a[i + n / 2];
        }
        bool f = true;
        for(int i = 0; i < n; i++)
        {
            if(b[i] == (b[(i + 1) % n]))
            {
                f = false;
            }
        }
        if(f)
        {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++)
            {
                cout << b[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}