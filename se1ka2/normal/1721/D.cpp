#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[100005], b[100005];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<vector<int>> d, e;
        vector<int> v(n), w(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = a[i];
            w[i] = b[i];
        }
        d.push_back(v);
        e.push_back(w);
        int ans = 0;
        for (int c = 30; c >= 0; c--)
        {
            bool f = true;
            for (int i = 0; i < (int)d.size(); i++)
            {
                int k = d[i].size();
                int s = 0;
                for (int j = 0; j < k; j++)
                {
                    s += ((d[i][j] >> c) & 1) + ((e[i][j] >> c) & 1);
                }
                if (s != k)
                {
                    f = false;
                }
            }
            if (f)
            {
                ans += (1 << c);
                vector<vector<int>> nd, ne;
                for (int i = 0; i < (int)d.size(); i++)
                {
                    int k = d[i].size();
                    vector<int> x[2];
                    vector<int> y[2];
                    for (int j = 0; j < k; j++)
                    {
                        if ((d[i][j] >> c) & 1)
                        {
                            x[0].push_back(d[i][j]);
                        }
                        else
                        {
                            x[1].push_back(d[i][j]);
                        }
                        if (!((e[i][j] >> c) & 1))
                        {
                            y[0].push_back(e[i][j]);
                        }
                        else
                        {
                            y[1].push_back(e[i][j]);
                        }
                    }
                    if (x[0].size())
                    {
                        nd.push_back(x[0]);
                        ne.push_back(y[0]);
                    }
                    if (x[1].size())
                    {
                        nd.push_back(x[1]);
                        ne.push_back(y[1]);
                    }
                }
                swap(d, nd);
                swap(e, ne);
            }
        }
        cout << ans << "\n";
    }
}