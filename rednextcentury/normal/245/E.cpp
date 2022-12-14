#include<bits/stdc++.h>

using namespace std;
int ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int n=s.length();
    string x="";
    int num=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='+')
            num++;
        else if (num==0)
            x+="+";
        else
            num--;
    }
    s=x+s;
    n=s.length();
    int last=-1;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='+')
            ret[i]++;
        else
            ret[i]--;
    }
    int now=0;
    int ans=0;
    for (int i=0;i<=n;i++)
        now+=ret[i],ans=max(ans,now);
    cout<<ans<<endl;
}