# include <bits/stdc++.h>
using namespace std;
int a[1000002];
int n;
long long get(long long X)
{
    map<long long,long long> mp;
    long long sum=0;
    mp[0]=1;
    long long ret=0;
    for (int i=0;i<n;i++)
    {
        sum+=a[i];
        ret+=mp[sum-X];
        mp[sum]++;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>n>>k;
    long long l=-100000000000000LL;
    long long r=100000000000000LL;
    long long cur=1;
    for (int i=0;i<n;i++)
        cin>>a[i];
    long long ret=0;
    if (k==1)
        ret=get(1);
    else if (k==-1)
        ret=get(1)+get(-1);
    else
    {
        while(cur>=l && cur<=r)
        {
            ret+=get(cur);
            cur*=k;
        }
    }
    cout<<ret<<endl;
}