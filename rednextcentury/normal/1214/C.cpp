#include <bits/stdc++.h>
using namespace std;
bool check(string s)
{
    int sum=0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='(')sum++;
        else sum--;
        if (sum<0)return 0;
    }
    return sum==0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    string s;
    int n;
    cin>>n;
    cin>>s;
    int L=-1,R=-1;
    int sum=0;
    bool ok=0;
    if (check(s))ok=1;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]==')')
        {
            if (L==-1)L=i;
            sum--;
        }
        else
        {
            R=i;
            sum++;
        }
    }
    if (L!=-1)
    {
        string t="";
        for (int i=0;i<s.size();i++)
        {
            if (i!=L)t+=s[i];
        }
        t+=")";
        if (check(t))ok=1;
    }
    if (R!=-1)
    {
        string t="(";
        for (int i=0;i<s.size();i++)
        {
            if (i!=R)t+=s[i];
        }
        if (check(t))ok=1;
    }
    if (ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}