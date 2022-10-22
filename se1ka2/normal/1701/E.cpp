#include <iostream>
#include <vector>
using namespace std;

vector<int> Zalgorithm(string &s)
{
    int n = s.size();
    vector<int> a(n);
    a[0] = n;
    int i = 1, j = 0;
    while (i < n)
    {
        while (i + j < n && s[i + j] == s[j])
            j++;
        a[i] = j;
        if (j == 0)
        {
            i++;
            continue;
        }
        int k = 1;
        while (i + k < n && k + a[k] < j)
        {
            a[i + k] = a[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        string s, t;
        cin >> n >> m >> s >> t;
        int d[5005], e[5005];
        int i = 0;
        bool f = true;
        for (int j = 0; j < m; j++)
        {
            while (i < n && s[i] != t[j])
            {
                i++;
            }
            if (i == n)
            {
                f = false;
                break;
            }
            d[j] = i++;
        }
        i = n;
        for (int j = m - 1; j >= 0; j--)
        {
            while (i > 0 && s[i - 1] != t[j])
            {
                i--;
            }
            if (i == 0)
            {
                f = false;
                break;
            }
            e[j] = --i;
        }
        if (!f)
        {
            cout << -1 << endl;
            continue;
        }
        int ans = n;
        for (int i = 0; i < m; i++)
        {
            if (s[i] != t[i])
            {
                break;
            }
            ans--;
        }
        for (int j = 0; j < m; j++)
        {
            string w = t.substr(j) + s;
            vector<int> z = Zalgorithm(w);
            for (int l = 0; l < n; l++)
            {
                int x = min(z[l + (m - j)], m - j);
                int r = l + x;
                int k = j + x;
                if (l < d[j] || (k < m && r > e[k]))
                {
                    continue;
                }
                ans = min(ans, (n - r) + l * 2 - j + 1);
            }
        }
        cout << ans << endl;
    }
}