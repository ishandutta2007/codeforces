# include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int a[1000000];
int main()
{
    string s;
    cin>>s;
    int c=0;
    int ans=0;
    for (int i=s.size()-1;i>=1;i--)
    {
        s[i]+=c;
        c=0;
        if (s[i]=='2')s[i]='0',c=1;
        if (s[i]=='0')ans++;
        else c++,ans+=2;
    }
    s[0]+=c;
    if (s[0]!='1')ans++;
    cout<<ans<<endl;
}