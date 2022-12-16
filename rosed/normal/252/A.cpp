#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200010],s[200010];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
   
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }

    int ans=0;

    for(int r=1;r<=n;++r)//
    {
        for(int l=1;l<=r;++l)
        {
            ans=max(ans,s[r]^s[l-1]);
        }
    }
    cout<<ans<<'\n';

    return 0;
}
/*


a a b

t=b-a;

3 4 5
3 3 4
2 3 3
2 2 2

2 4 4

*/