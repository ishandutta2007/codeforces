#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 0, a[2], n, ans = 0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i%2];
        if(a[i%2] > a[(i+1)%2])
        {
            ++cnt;
            ans = max(ans, cnt);
        }
        else
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    cout<<ans<<endl;
    return 0;
 }