#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m)
{
    if(m == 0)
    {
        return n;
    }
    return gcd(m, n % m);
}

ll lcm(ll n, ll m)
{
    return n / gcd(n, m) * m;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int p[205];
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
        }
        bool b[205]{0};
        ll ans = 1;
        for(int i = 0; i < n; i++)
        {
            if(b[i])
            {
                continue;
            }
            int u = i;
            string t;
            while(!b[u])
            {
                b[u] = true;
                t += s[u];
                u = p[u];
            }
            int k = t.size();
            for(int j = 1; j <= k; j++)
            {
                if(k % j)
                {
                    continue;
                }
                bool f = true;
                for(int l = 0; l < j; l++)
                {
                    for(int m = l; m + j < k; m += j)
                    {
                        if(t[m] != t[m + j])
                        {
                            f = false;
                        }
                    }
                }
                if(f)
                {
                    ans = lcm(ans, j);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}