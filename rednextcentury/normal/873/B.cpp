#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='1')
            a[i+1]=1;
        else a[i+1]=-1;
    }
    mp[0]=0;
    int cur=0;
    int ret=0;
    for (int i=1;i<=n;i++)
    {
        cur+=a[i];
        if (mp.find(cur)!=mp.end())
            ret=max(ret,i-mp[cur]);
        if (mp.find(cur)==mp.end())
            mp[cur]=i;
        mp[cur]=min(mp[cur],i);
    }
    cout<<ret<<endl;
}