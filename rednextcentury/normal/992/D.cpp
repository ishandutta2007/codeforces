#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> a[1000000];
int main()
{
    long long n,k;
    long long N;
    n=0;
    cin>>N>>k;
    for (int i=1;i<=N;i++)
    {
        int x;
        cin>>x;
        if (n==0)
            a[n++]=make_pair(x,1);
        else if (a[n-1].first==x && x==1)
            a[n-1].second++;
        else
            a[n++]=make_pair(x,1);
    }
    long long ret=0;
    for (int i=0;i<n;i++)
    {
        for (long long x=0;x<a[i].second;x++)
        {
            long long p=1;
            long long s=-x*a[i].first;
            for (int j=i;j<n;j++)
            {
                if (a[j].first==1)
                {
                    if (p%k==0)
                    {
                        long long need = p/k;
                        if (s+a[j].second >= need && need>s)
                            ret++;
                    }
                    s+=a[j].second;
                    continue;
                }
                else
                {
                    if (1800000000000000000LL/p < a[j].first)
                        break;
                    p*=a[j].first;
                    s+=a[j].first;
                    if (p%s==0 && p/s==k)
                        ret++;
                }
            }
        }
    }
    cout<<ret<<endl;
}