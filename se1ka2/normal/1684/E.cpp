#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int a[100005];
        map<int, int> d;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            d[a[i]]++;
        }
        int c = 0;
        int x;
        for(x = 0; x <= n; x++)
        {
            if(!d[x])
            {
                if(c == k)
                {
                    break;
                }
                c++;
            }
        }
        vector<int> v;
        for(auto itr = d.begin(); itr != d.end(); itr++)
        {
            if(itr->first >= x)
            {
                v.push_back(itr->second);
            }
        }
        sort(v.begin(), v.end());
        int m = v.size();
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            if(v[i] > k)
            {
                ans = m - i;
                break;
            }
            k -= v[i];
        }
        cout << ans << endl;
    }
}