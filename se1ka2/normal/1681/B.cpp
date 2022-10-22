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
        int a[200005];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int m;
        cin >> m;
        int b[200005];
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        int x = 0;
        for(int i = m - 1; i >= 0; i--)
        {
            if(x < n - b[i])
            {
                x += b[i];
            }
            else
            {
                x -= n - b[i];
            }
        }
        cout << a[x] << endl;
    }
}