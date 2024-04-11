#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s = "RGBYW";
int N;

int has[5][5];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string x; cin >> x;
        int a = 0, b = x[1] - '1';
        for (int j = 0; j < 5; j++)
            if (s[j] == x[0])
                a = j;
        has[a][b]++;
    }

    int ans = 30;
    for (int i = 0; i < 1024; i++)
    {
        set <int> s;
        bool bad = false;
        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                int t = 0;
                for (int l = 0; l < 10; l++)
                {
                    int v = 0;
                    if (i & (1 << l))
                    {
                        if (l < 5 && l == x)
                            v++;
                        if (l >= 5 && l - 5 == y)
                            v++;
                    }
                    v *= (1 << l);
                    t += v;
                }
                if (has[x][y])
                {
                    if (s.find(t) != s.end())
                    {
                        bad = true;
                    }
                    s.insert(t);
                }
            }
        }
        if (!bad)
        {
            ans = min (ans, __builtin_popcount(i));
        }
    }
    cout << ans << "\n";
}