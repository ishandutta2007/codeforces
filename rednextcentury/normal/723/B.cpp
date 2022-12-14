#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    bool par=0;
    int len=0;
    int ans=0,num=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='_' || s[i]==')' || s[i]=='(')
        {
            if (len!=0)
            {
                if (par)num++;
                else ans=max(ans,len);
            }
            len=0;
        }
        else len++;
        if (s[i]=='(')par=1;
        if (s[i]==')')par=0;
    }
    if (len)
        ans=max(ans,len);
    cout<<ans<<' '<<num<<endl;
}