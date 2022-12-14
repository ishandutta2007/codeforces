#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    for (int i=p;i<n;i++)
    {
        if (s[i]=='.')
        {
            if (s[i-p]=='.')
                s[i]='1',s[i-p]='0';
            else
                s[i]='1'-s[i-p]+'0';
        }
        else
        {
            if (s[i-p]=='.')
                s[i-p]='1'-s[i]+'0';
        }
    }
    bool ok=0;
    for (int i=0;i<s.size();i++)
        if (s[i]=='.')
            s[i]='1';
    for (int i=0;i+p<s.size();i++)
        if (s[i]!=s[i+p])ok=1;
    if (ok)
        cout<<s<<endl;
    else
        cout<<"No"<<endl;
}