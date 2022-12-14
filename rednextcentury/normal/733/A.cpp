#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ans=0;
    int last=-1;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='E' || s[i]=='O' || s[i]=='I' || s[i]=='U' || s[i]=='A' || s[i]=='Y')
        {
                ans=max(ans,i-last);
                last=i;
        }
    }
    ans=max(ans,(int)s.size()-last);
    cout<<ans<<endl;
}