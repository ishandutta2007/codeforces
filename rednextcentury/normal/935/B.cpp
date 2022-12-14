#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int x=0,y=0;
    int n;
    cin>>n;
    string ret="G";
    for (int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if (c=='U')y++;
        else x++;
        if (x>y)ret+="1";
        else if (x<y)ret+="2";
        else ret+="G";
    }
    int ans=0;
    for (int i=2;i<ret.size();i++)
    {
        if (ret[i]=='1' && ret[i-2]=='2')
            ans++;
        if (ret[i]=='2' && ret[i-2]=='1')
            ans++;
    }
    cout<<ans<<endl;
}