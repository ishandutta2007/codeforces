#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l,r,x,y,k;
    cin>>l>>r>>x>>y>>k;
    for (int i=x;i<=y;i++)
    {
        long long need=((long long)i)*k;
        if (need<=r && need>=l)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}