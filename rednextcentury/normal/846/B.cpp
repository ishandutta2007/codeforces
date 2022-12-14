#include <bits/stdc++.h>
using namespace std;
long long t[10000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n,k,m;
    cin>>n>>k>>m;
    long long sum=0;
    for (int i=0;i<k;i++)
        cin>>t[i],sum+=t[i];
    int ret=0;
    for (int i=0;i<=n;i++)
    {
        if (i*sum > m)
            break;
        long long x = m - i*sum;
        multiset<long long> s;
        for (int j=0;j<n-i;j++)
            for (int o=0;o<k;o++)
                s.insert(t[o]);
        int ans=(k+1)*i;
        while(!s.empty())
        {
            int cur = *s.begin();
            s.erase(s.begin());
            if (x>=cur)
                x-=cur,ans++;
            else break;
        }
        ret=max(ret,ans);
    }
    cout<<ret<<endl;
}