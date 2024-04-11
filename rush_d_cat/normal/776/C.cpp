#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int NICO = 100000 + 10;
map<LL, int> mp;
vector<LL> vec;
int n, k;
LL pre[NICO], ans;
void init()
{
    if(k==1)
    {
        vec.push_back(1);
    } else
    if(k==-1)
    {
        vec.push_back(1);
        vec.push_back(-1);
    } else {
        LL tmp = 1;
        vec.push_back(1);
        while(abs(tmp) <= 1e14)
        {
            vec.push_back(tmp*(LL)k);
            tmp *= (LL)k;
        }
    }
}
int main()
{
    cin >> n >> k;
    init();
    for(int i=1;i<=n;i++)
    {
        int x; scanf("%d", &x);
        pre[i] = pre[i-1] + (LL)x;
    }
    for(int i=0;i<=n;i++)
    {
        ans += mp[pre[i]];
        for(int j=0;j<vec.size();j++)
        {
            mp[pre[i]+vec[j]] += 1; 
        }
    }
    cout << ans << endl;
}