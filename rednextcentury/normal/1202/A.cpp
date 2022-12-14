#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int first=0;
        for (int i=0;i<b.size();i++)
        {
            if (b[i]=='1')
            {
                first=i;
                break;
            }
        }
        int ans=0;
        for (int i=first;i<a.size();i++)
        {
            if (a[i]=='1')
            {
                ans=i-first;
                break;
            }
        }
        cout<<ans<<endl;
    }
}