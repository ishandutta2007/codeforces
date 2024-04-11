#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
pair<int,int> a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,y,x;
    cin>>n>>x>>y;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+1+n);
    long long ret=0;
    int mod=1000000007;
    for (int i=1;i<=n;i++)
    {
        if (s.empty())
        {
            s.insert(a[i].second);
            ret=ret+x+(a[i].second-a[i].first)*y;
            ret%=mod;
        }
        else
        {
            multiset<int>::iterator it=s.lower_bound(a[i].first);
            if (it!=s.begin())
            {
                it--;
                long long p = *it;
                s.erase(it);
                ret=ret+min((a[i].first-p)*y,x)+((a[i].second-a[i].first)*y)%mod;
                ret%=mod;
                s.insert(a[i].second);
            }
            else
            {
                s.insert(a[i].second);
                ret=ret+x+((a[i].second-a[i].first)*y)%mod;
                ret%=mod;
            }
        }
    }
    cout<<ret<<endl;
}