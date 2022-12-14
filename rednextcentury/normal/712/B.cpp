#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++)
        a[s[i]]++;
    int n=s.size();
    if (n%2)
    {
        cout<<-1<<endl;
        return 0;
    }
    int ans=10000000;
    for (int i=0;i<=n/2;i++)
    {
        int x=n/2-i;
        int cur=abs(a['R']-i)+abs(a['L']-i)+abs(a['U']-x)+abs(a['D']-x);
        cur/=2;
        ans=min(ans,cur);
    }
    cout<<ans<<endl;
}