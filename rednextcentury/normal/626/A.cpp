#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        int x=0,y=0;
        for (int j=i;j<n;j++)
        {
            if (s[j]=='U') y++;
            if (s[j]=='D') y--;
            if (s[j]=='R') x++;
            if (s[j]=='L') x--;
            if (x==0 && y==0)
                ans++;
        }
    }
    cout<<ans<<endl;
}