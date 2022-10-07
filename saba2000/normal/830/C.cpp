#include<bits/stdc++.h>
using namespace std;
long long a[109],k,n;
long long ans=0;
vector<long long> p;
set<long long> s;
void add(long long x)
{
int z=1;
while((x+z-1)/z>=100000)
{p.push_back((x+z-1)/z);

z++;}
}
bool check (long long d)
{long long s=0;
    for (long long i=0; i<n; i++)
    s+=d*((a[i]+d-1)/d)-a[i];// d=3 a=10
    return s<=k;
}
main()
{cin>>n>>k;
for (long long i=0; i<n; i++)
    cin>>a[i];
for (long long i=0; i<n; i++)
{
    add(a[i]);
}
p.push_back(100000);
sort(p.begin(),p.end());
p.push_back(100000000000000);
//cout<<p[p.size()-1]<<endl;
long long ans=0;
long long z=-1;
//17
//0 1 1 3 3 1
for (long long i=0; i<p.size()-1; i++)
{
    if(check(p[i]))
z=i;
}
if(z==-1)
 {for (int i=200000; i>=0; i--)
 if(check(i)) {cout<<i<<endl; return 0;}
 }
long long l=p[z],r=p[z+1]-1;
    while(l<r)
    {
        long long mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}