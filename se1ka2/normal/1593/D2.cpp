#include <iostream>
#include <map>
using namespace std;

int gcd(int n, int m)
{
    if(m == 0)
    {
        return n;
    }
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[45];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 1;
        for(int l = 0; l < n; l++)
        {
            map<int, int> mp;
            mp[0] = 1;
            for(int i = l + 1; i < n; i++)
            {
                map<int, int> np;
                for(auto itr = mp.begin(); itr != mp.end(); itr++)
                {
                    int x = itr->first;
                    np[x] = max(np[x], itr->second);
                    int g = gcd(x, abs(a[i] - a[l]));
                    np[g] = max(np[g], mp[x] + 1);
                }
                swap(mp, np);
            }
            if(mp[0] * 2 >= n)
            {
                ans = -1;
            }
            for(auto itr = mp.begin(); itr != mp.end(); itr++)
            {
                if(ans >= 1 && itr->second * 2 >= n)
                {
                    ans = max(ans, itr->first);
                }
            }
        }
        cout << ans << endl;
    }
}