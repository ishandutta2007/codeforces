#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    s="."+s;
    if (s[a]==s[b])
        cout<<0<<endl;
    else
    {
        int mn=1000000;
        int l0=-1,l1=-1;
        for (int i=1;i<s.size();i++)
        {
            if (s[i]=='0')
            {
                if (l1!=-1)
                    mn=min(mn,i-l1);
                l0=i;
            }
            else
            {
                if (l0!=-1)
                    mn=min(mn,i-l0);
                l1=i;
            }
        }
        cout<<mn<<endl;
    }
}