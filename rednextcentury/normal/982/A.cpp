#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (n==1 && s=="0")
    {
        cout<<"No"<<endl;
        return 0;
    }

    int l = -1;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='1')
        {
            if (l!=-1)
            {
                if (i-l==1)
                {   cout<<"No"<<endl;return 0; }
                if (i-l>3)
                {   cout<<"No"<<endl;return 0; }
            }
            else if (i>1)
            {
                cout<<"No"<<endl;
                return 0;
            }
            l = i;
        }
    }
    if (n-l-1>1)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}