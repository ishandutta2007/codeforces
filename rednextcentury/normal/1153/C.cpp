#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    if (n%2)
    {
        cout<<":("<<endl;
        return 0;
    }
    int m=n/2;
    int l=0,r=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='(')l++;
        else if (s[i]==')')r++;
    }
    if (l>m || r>m)
    {
        cout<<":("<<endl;
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        if (s[i]=='?' && l<m)
        {
            l++;
            s[i]='(';
        }
        else if (s[i]=='?')
        {
            r++;
            s[i]=')';
        }
    }
    int S=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='(')
                S++;
        else S--;

        if (S<0)
        {
            cout<<":("<<endl;
            return 0;
        }
        if (S==0 && i+1!=n)
        {
            cout<<":("<<endl;
            return 0;
        }
    }
    if (S==0)
    {
        cout<<s<<endl;
        return 0;
    }
    cout<<":("<<endl;
}