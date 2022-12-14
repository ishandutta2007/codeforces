#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    int l=0;
    bool a=0;
    while(l<s.size())
    {
        if (s[l]=='[')
            a=1;
        if (s[l]==':' && a)
            break;
        l++;
    }
    int r=s.size()-1;
    a=0;
    while(r>=0)
    {
        if (s[r]==']')
            a=1;
        if (s[r]==':' && a)
            break;
        r--;
    }
    if (r<=l)
    {
        cout<<-1<<endl;
    }
    else
    {
        int num=4;
        for (int i=l;i<=r;i++)
            num+=s[i]=='|';
        cout<<num<<endl;
    }
}