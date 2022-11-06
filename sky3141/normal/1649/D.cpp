#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 1000000 + 9;

int n, limit;
int a[MAXN];
int s[MAXN];

bool solve()
{
    cin >> n >> limit;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    n = unique(a, a + n) - a;

    fill(s, s + limit + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        ++s[a[i]];
    }
    for (int i = 1; i <= limit; ++i)
    {
        s[i] += s[i - 1];
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int l = 1, r; l <= a[i]; l = r + 1)
    //     {
    //         int tmp = a[i] / l;
    //         r = a[i] / tmp;
    //         if (s[r] > s[l - 1] && s[tmp] == s[tmp - 1])
    //         {
    //             return false;
    //         }
    //     }
    // }
    for (int j = 1; j <= limit; ++j)
    {
        if (s[j] == s[j - 1])
        {
            for (int k = 0; k < n; ++k)
            {
                if ((long long)j * a[k] > limit)
                    break;
                int t = j * a[k] + a[k] - 1;
                if (t > limit)
                    t = limit;
                if (s[t] > s[j * a[k] - 1])
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cout << (solve() ? "Yes\n" : "No\n");
    }


    return 0;
}