#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1005];
bool ans[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        k--;
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = false;
            }
        }
        string s[1005];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < k; i++)
        {
            s[i][n - 1 - (k - 1 - i)] = '0';
            s[n - 1 - i][k - 1 - i] = '0';
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[i][j] == '0')
                {
                    v[i].push_back(j);
                }
            }
            v[i].push_back(n);
        }
        int d[1005];
        for (int i = 0; i < n; i++)
        {
            d[i] = -1;
        }
        for (int i = 0; i < k; i++)
        {
            int j = n - 1;
            int x = i;
            while (x < n)
            {
                int y = *upper_bound(v[x].begin(), v[x].end(), d[x]);
                d[x] = j;
                for (; j > y; j--)
                {
                    ans[x][j] = true;
                }
                ans[x][j] = true;
                x++;
            }
        }
        bool f = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[i][j] == '0' && !ans[i][j])
                {
                    f = false;
                }
            }
        }
        if (f)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << ans[i][j];
                }
                cout << "\n";
            }
        }
        else
        {
            cout << "NO\n";
        }
    }
}