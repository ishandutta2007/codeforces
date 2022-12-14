#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x=0,y=0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int t;
        string s;
        cin>>t>>s;
        if (s=="East" || s=="West")
        {
            if (y==0 || y==20000)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            continue;
        }
        for (int j=0;j<t;j++)
        {
            if (s[0]=='N')
            {
                if (y==0)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                y--;
            }
            else
            {
                if (y==20000)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                y++;
            }
        }
    }
    if (y!=0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}