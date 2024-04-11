#include <bits/stdc++.h>
using namespace std;
long long t[1000000];
long long a[1000000];
multiset<long long> s;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
        cin>>t[i];
    long long rem=0;
    for (int i=0;i<n;i++)
    {
        s.insert(a[i]+rem);
        long long cur=0;
        while(1)
        {
            if (s.size()==0)
                break;
            long long x=*s.begin();
            x-=rem;
            if (x<=t[i])
            {
                s.erase(s.begin());
                cur+=x;
            }
            else
            {
                cur+=((long long)(s.size()))*t[i];
                break;
            }
        }
        cout<<cur<<' ';
        rem+=t[i];
    }
}