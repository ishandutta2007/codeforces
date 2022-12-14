# include <iostream>
# include <algorithm>
# include <set>
# include <stdio.h>
using namespace std;
long long a[1000000];
long long b[1000000];
long long pen1,pen2;
long long ans1[1000002];
long long ans2[1000002];
int main()
{
    long long n,m,k,p;
    cin>>n>>m>>k>>p;
    for (long long i=0;i<n;i++)
    {
        for (long long j=0;j<m;j++)
        {
            long long x;
            cin>>x;
            a[i]+=x;
            b[j]+=x;
        }
    }
    multiset<long long> s1;
    multiset<long long> s2;
    for (long long i=0;i<n;i++)
        s1.insert(a[i]);
    for (long long i=0;i<m;i++)
        s2.insert(b[i]);
    multiset<long long>::iterator it;
    for (long long i=0;i<k;i++)
    {
        it=s1.end();
        it--;
        int x1=*it;
        ans1[i+1]+=x1+ans1[i];
        s1.erase(it);
        s1.insert(x1-m*p);
    }
    for (long long i=0;i<k;i++)
    {
        it=s2.end();
        it--;
        int x2=*it;
        ans2[i+1]+=x2+ans2[i];
        s2.erase(it);
        s2.insert(x2-n*p);
    }
    long long ans=ans1[0]+ans2[k];
    for (long long i=0;i<=k;i++)
        ans=max(ans,ans1[i]+ans2[k-i]-i*(k-i)*p);
    cout<<ans<<endl;
}