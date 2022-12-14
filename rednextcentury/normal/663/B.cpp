#include <bits/stdc++.h>
using namespace std;
string st[]={"1990","1991","1992","1993","1994","1995","1996","1997","1998","1989"};
string Get(string cur,string s)
{

    string l = cur;
    string r = s;
    reverse(l.begin(),l.end());
    reverse(r.begin(),r.end());
    //cout<<l<<' '<<r<<endl;
    bool ok=0;
    if (l.size()>r.size())
    {
        reverse(l.begin(),l.end());
        return l;
    }
    bool is=1;
    for (int i=0;i+1<l.size();i++)
        is&=(l[i]==r[i]);
    if (is && l[l.size()-1]>r[l.size()-1])
    {
        r[l.size()-1]=l[l.size()-1];
        reverse(r.begin(),r.end());
        return r;
    }
    for (int i=l.size();i<r.size();i++)
    {
        if (r[i]<'9')
        {
            for (int j=l.size();j<i;j++)
                l+="0";
            l+=char(r[i]+1);
            for (int j=i+1;j<r.size();j++)
                l+=r[i];
            reverse(l.begin(),l.end());
            return l;
        }
    }
    for (int i=0;i<l.size();i++)
        r[i]=l[i];
    r+="1";
    reverse(r.begin(),r.end());
    return r;
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        reverse(ss.begin(),ss.end());
        string s = st[ss[0]-'0'];
        string cur="";
        cur+=char(ss[0]);
        for (int i=1;i<ss.size();i++)
        {
            char x = ss[i];
            if (x>='0' && x<='9')
            {
                cur=x+cur;
                s = Get(cur,s);
if(s[0]=='0')s="1"+s;
            }
            else
                break;
        }
        cout<<s<<endl;
    }
}