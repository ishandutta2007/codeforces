#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int b[200005];
        for(int i = 0; i < n; i++)
        {
            b[i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            int a;
            cin >> a;
            a--;
            b[a]++;
        }
        int right = m * 2 + 1, left = 0;
        while(right - left > 1)
        {
            int mid = (right + left) / 2;
            ll c = 0, d = 0;
            for(int i = 0; i < n; i++)
            {
                if(b[i] > mid)
                {
                    c += b[i] - mid;
                }
                else
                {
                    d += (mid - b[i]) / 2;
                }
            }
            if(d >= c)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        cout << right << endl;
    }
}