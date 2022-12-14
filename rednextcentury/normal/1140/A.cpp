#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ret=0,mx=0;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if (mx<i)
        {
            ret++,mx=a;
        }
        else
            mx=max(mx,a);
    }
    cout<<ret<<endl;
}