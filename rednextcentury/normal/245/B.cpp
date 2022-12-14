#include<bits/stdc++.h>

using namespace std;
int num[3];
int main()
{
    string s;
    cin>>s;
    string ans="";
    int n=s.length();
    int i=0;
    if (s[0]=='f')
        ans+="ftp://",i=3;
    else
        ans+="http://",i=4;
    int loc=-1;
    for (int j=i;j<n-1;j++)
    {
        if (s[j]=='r' && s[j+1]=='u')
            loc=j;
    }
    while(i<loc)
    {
        ans+=s[i];
        i++;
    }

    ans+=".ru";
    i=loc+2;
    if (i!=n)
    {
        ans+='/';
        while(i<n)
            ans+=s[i],i++;
    }
    cout<<ans<<endl;
}