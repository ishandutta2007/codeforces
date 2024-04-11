#include <iostream>
#include <vector>
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
        vector<vector<ll>> c(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c[i][j];
            }
        }
        for (int i = 1; i < n; i++)
        {
            ll s = 0;
            for (int j = 0; j < m; j++)
            {
                s += (c[i][j] - c[0][j]) * j;
            }
            if (s)
            {
                if (s < 0)
                {
                    cout << 1 << " " << -s << endl;
                }
                else
                {
                    cout << i + 1 << " " << s << endl;
                }
                break;
            }
        }
    }
}