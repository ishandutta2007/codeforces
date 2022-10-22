#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool b[100005];
    for (int i = 1; i <= n; i++)
    {
        b[i] = true;
    }
    int p;
    int ans = 1;
    for (p = 2; p * p <= n; p++)
    {
        if (b[p])
        {
            cout << "B " << p << endl;
            int t;
            cin >> t;
            for (int i = p; i <= n; i += p)
            {
                if (b[i])
                {
                    b[i] = false;
                }
            }
            int q = p;
            while (true)
            {
                cout << "A " << q << endl;
                int c;
                cin >> c;
                if (c == 0)
                {
                    ans *= q / p;
                    break;
                }
                q *= p;
                if(q > n)
                {
                    ans *= q / p;
                    break;
                }
            }
        }
    }
    if (ans >= 2)
    {
        for (; p <= n; p++)
        {
            if (b[p])
            {
                b[p] = false;
                cout << "B " << p << endl;
                int c;
                cin >> c;
                if (c >= 2)
                {
                    ans *= p;
                }
            }
        }
    }
    else
    {
        int c = 0;
        int l = p;
        cout << "A " << 1 << endl;
        int x;
        cin >> x;
        for (; p <= n; p++)
        {
            if (b[p])
            {
                cout << "B " << p << endl;
                int t;
                cin >> t;
                c++;
                if (c == 100)
                {
                    cout << "A " << 1 << endl;
                    int y;
                    cin >> y;
                    if (x - y == 99)
                    {
                        break;
                    }
                    else
                    {
                        c = 0;
                        l = p + 1;
                        x = y;
                    }
                }
            }
        }
        for (int i = l; i <= min(p, n); i++)
        {
            if (b[i])
            {
                cout << "A " << i << endl;
                int e;
                cin >> e;
                if (e)
                {
                    ans = i;
                    break;
                }
            }
        }
    }
    cout << "C " << ans << endl;
}