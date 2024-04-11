#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int NICO = 200000 + 10;
const LL MOD = 1000000007;
map<LL, LL> mp, mp1;
LL n, k, ans;
LL a[NICO];
int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i] % k == 0)
        {
            ans += mp1[a[i]/k];
            mp1[a[i]] += mp[a[i]/k];
        }
        mp[a[i]]++;
    }
    cout << ans << endl;
}