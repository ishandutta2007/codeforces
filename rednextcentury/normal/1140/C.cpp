#include <bits/stdc++.h>
using namespace std;
multiset<long long> s;
pair<long long,long long> a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].second>>a[i].first;
    }
    sort(a+1,a+n+1);
    long long ret=0;
    long long sum=0;
    for (int i=n;i>=1;i--)
    {
        if (s.size()<k)
        {
            s.insert(a[i].second);
            sum+=a[i].second;
        }
        else
        {
            if (a[i].second>*s.begin())
            {
                sum-=*s.begin();
                s.erase(s.begin());
                s.insert(a[i].second);
                sum+=a[i].second;
            }
        }
        ret=max(ret,sum*a[i].first);
    }
    cout<<ret<<endl;
}