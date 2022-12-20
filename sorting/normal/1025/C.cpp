#include<iostream>

using namespace std;

#define endl "\n"

int main ()
{
    string s;
    int i,l=1,r=1,res,curr;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;

    if(s.size()==1)
    {
        cout<<"1"<<endl;
        return 0;
    }

    for(i=1;i<s.size();i++)
    {
        if(s[i]!=s[i-1])
            l++;
        else
            break;
    }

    for(i=s.size()-2;i>=0;i--)
    {
        if(s[i]!=s[i+1])
            r++;
        else
            break;
    }

    if(l==s.size())
        r=0;

    res=0;
    curr=1;

    for(i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1])
        {
            res=max(res,curr);
            curr=1;
        }
        else
            curr++;
    }

    res=max(res,curr);
    if(s[0]!=s[s.size()-1])res=max(res,l+r);

    cout<<res<<endl;

    return 0;
}