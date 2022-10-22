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

struct Trie
{
    vector<vector<int>> t;
    vector<int> d;

    Trie()
    {
        vector<int> e(26);
        for (int i = 0; i < 26; i++)
        {
            e[i] = -1;
        }
        t.push_back(e);
        d.push_back(0);
    }

    int get(string s)
    {
        int n = s.size();
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (t[c][s[i] - 'a'] == -1)
            {
                return 0;
            }
            c = t[c][s[i] - 'a'];
        }
        return d[c];
    }

    void set(string s, int x)
    {
        int n = s.size();
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (t[c][s[i] - 'a'] == -1)
            {
                t[c][s[i] - 'a'] = (int)t.size();
                vector<int> e(26);
                for (int j = 0; j < 26; j++)
                {
                    e[j] = -1;
                }
                t.push_back(e);
                d.push_back(0);
            }
            c = t[c][s[i] - 'a'];
        }
        d[c] = x;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a = Zalgorithm(s);
    a.push_back(0);
    Trie T;
    for (int i = n; i > 0; i--)
    {
        if (a[i] + i == n)
        {
            string t;
            for (int j = a[i]; j < a[i] + 10; j++)
            {
                if(j < n)
                {
                    t += s[j];
                }
                else
                {
                    t += t[j - n];
                }
                T.set(t, j + 1);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        string t;
        cin >> t;
        int m = t.size();
        int ans[20]{0};
        for (int j = 1; j < m; j++)
        {
            bool f = true;
            for (int k = j; k < m; k++)
            {
                if(k - j < n)
                {
                    if (s[k - j] != t[k])
                    {
                        break;
                    }
                    ans[k + 1] = max(ans[k + 1], (k + 1) - j);
                }
                else
                {
                    if(t[k - j - n] != t[k])
                    {
                        break;
                    }
                    ans[k + 1] = max(ans[k + 1], (k + 1) - j);
                }
            }
        }
        for (int j = 1; j <= m; j++)
        {
            ans[j] = max(ans[j], T.get(t.substr(0, j)));
        }
        for (int j = 1; j <= m; j++)
        {
            cout << ans[j] << " ";
        }
        cout << "\n";
    }
}