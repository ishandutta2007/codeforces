#include <bits/stdc++.h>
using namespace std;
string s;
int ans=10000000;
string ret="-1";
void calc(string x,int num)
{
    int i=0;
    for (i=0;i<x.size();i++)
    {
        if (x[i]=='0')num++;
        else break;
    }
    if (i==x.size() && i==0)
        return;
    else if (i==x.size()){
        if (num-1<ans)
            ans=num-1,ret="0";
        ans=min(ans,num-1);
    }
    else
    {
        if (num<ans)
            ans=num,ret=x.substr(i,x.size()-i);
    }
}
int main()
{
    cin>>s;
    int num=0;
    for (int i=0;i<s.size();i++)
        num+=s[i]-'0';
    num%=3;
    if (num==0)
    {
        cout<<s<<endl;
        return 0;
    }
    if (num==1)
    {
        int f1=-1,f2=-1,s2=-1;
        for (int i=s.size()-1;i>=0;i--)
        {
            if ((s[i]-'0')%3==1)
            {
                f1=max(f1,i);
            }
            else if ((s[i]-'0')%3==2)
            {
                if (f2==-1)f2=i;
                else if (s2==-1)s2=i;
            }
        }
        string a=s;
        if (f1!=-1){
        a.erase(f1,1);
        calc(a,1);
        }
        a=s;
        if (min(f2,s2)!=-1){
        a.erase(f2,1);
        a.erase(s2,1);
        calc(a,2);
        }
    }
    else
    {
        int f2=-1,f1=-1,s1=-1;
        for (int i=s.size()-1;i>=0;i--)
        {
            if ((s[i]-'0')%3==2)
            {
                f2=max(f2,i);
            }
            else if ((s[i]-'0')%3==1)
            {
                if (f1==-1)f1=i;
                else if (s1==-1)s1=i;
            }
        }
        string a=s;
        if (f2!=-1){
        a.erase(f2,1);
        calc(a,1);
        }
        a=s;
        if (min(f1,s1)!=-1){
        a.erase(f1,1);
        a.erase(s1,1);
        calc(a,2);
        }
    }
    cout<<ret<<endl;
}