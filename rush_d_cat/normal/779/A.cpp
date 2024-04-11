#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int NICO = 1000000 + 10;
int n, a[NICO], b[NICO];
int cnt1[12], cnt2[12];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt1[a[i]] ++;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
        cnt2[b[i]] ++;
    }
    int ans1 = 0, ans2 = 0, ok = 1;
    for(int i=1;i<=5;i++)
    {
        if(cnt1[i] > cnt2[i])
        {
            if((cnt1[i] - cnt2[i])%2) ok = 0;
            else ans1 += (cnt1[i] - cnt2[i])/2;
        }
        if(cnt1[i] < cnt2[i])
        {
            if((cnt2[i] - cnt1[i])%2) ok = 0;
            else ans2 += (cnt2[i] - cnt1[i])/2;
        }
    }
    if(ans1 != ans2) ok = 0;
    if(ok)
    {
        printf("%d\n", ans1);
    } else {
        printf("-1\n");
    }
}