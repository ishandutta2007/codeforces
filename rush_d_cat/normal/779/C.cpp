#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int NICO = 2000000 + 10;
int n, k, a[NICO], b[NICO];
vector<int> v;
int main()
{   
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int cnt = 0, ans = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
        if(b[i] >= a[i])
        {
            cnt ++;
            ans += a[i];
        }
    }
    if(cnt >= k)
    {
        for(int i=1;i<=n;i++)
        {
            if(b[i] < a[i])
            {
                ans += b[i];
            }
        }
    } else {
        for(int i=1;i<=n;i++)
        {
            if(b[i] < a[i])
            {
                ans += b[i];
                v.push_back(a[i] - b[i]);
            }
        }
        sort(v.begin(),v.end());
        int sz = min((int)v.size(), k-cnt);
        for(int i=0;i<sz;i++)
        {
            ans += v[i];
        }
    }
    cout << ans << endl;
}