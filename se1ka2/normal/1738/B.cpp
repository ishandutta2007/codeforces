#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        ll s[200005];
        for(int i = n - k + 1; i <= n; i++)
        {
            cin >> s[i];
        }
        if(k == 1)
        {
            cout << "Yes" << endl;
            continue;
        }
        ll d[200005];
        bool f = true;
        for(int i = n - 1; i > n - k; i--)
        {
            d[i] = (s[i + 1] - s[i]);
            if(i < n - 1 && d[i] > d[i + 1])
            {
                f = false;
            }
        }
        if(d[n - k + 1] * (n - k + 1) < s[n - k + 1])
        {
            f = false;
        }
        if(f)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}