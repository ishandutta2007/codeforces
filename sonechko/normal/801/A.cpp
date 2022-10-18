#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s;
    t=s;
    int res=0;
    for (int j=0; j<s.size(); j++)
    {
        s[j]='V';
        int ans=0;
        for (int i=1; i<s.size(); i++)
        if (s[i]=='K'&&s[i-1]=='V') ans++;
        res=max(res,ans);
        s[j]='K';
        ans=0;
        for (int i=1; i<s.size(); i++)
        if (s[i]=='K'&&s[i-1]=='V') ans++;
        res=max(res,ans);
        s[j]=t[j];
    }
    cout<<res<<endl;
}