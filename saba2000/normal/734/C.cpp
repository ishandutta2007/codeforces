#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,k,x,s,l,g;
pair<long long,long long> a[200009];
pair<long long,long long> a1[200009];
long long b[200009],c[200009];
long long check1(long long t)
{long long u=0,v=k-1;
while(u<v)
{long long r=(u+v+1)/2;
if (t+c[r]<=s) u=r;
else v=r-1;}
if (t+c[u]<=s) return b[u];
else return 0;}
long long check2(long long t)
{long long u=0,v=l-1;
while(u<v)
{long long r=(u+v+1)/2;
if (t+a1[r].first<=s) u=r;
else v=r-1;}
if (t+a1[u].first<=s) return a1[u].second;
else return x;}
main()
{cin>>n>>m>>k>>x>>s;
for (long long i=0; i<m; i++)
cin>>a[i].second;
for (long long i=0; i<m; i++)
cin>>a[i].first;
for (long long i=0; i<k; i++)
cin>>b[i];
for (long long i=0; i<k; i++)
cin>>c[i];
sort(a,a+m);
g=a[0].second;
l=1;
a1[0].first=a[0].first; a1[0].second=a[0].second;

for (long long i=1; i<m; i++)
if (a[i].second<g)
{a1[l].first=a[i].first; a1[l].second=a[i].second; g=a[i].second; l++;}
long long ans=n*x;

for(long long i=0; i<l; i++)
{
if (a1[i].first>s) continue;
long long e=check1(a1[i].first);
//cout<<a1[i].first<<" "<<a1[i].second<<" "<<e<<endl;
ans=min(ans,(long long)(n-e)*a1[i].second);

}     
for(long long i=0; i<k; i++)
{if (c[i]>s) continue;
long long e=check2(c[i]);
//cout<<i<<" "<<e<<endl;
ans=min(ans,(long long)(n-b[i])*e);
//cout<<e<<" "<<b[i]<<endl;
}    
cout<<ans<<endl;
//system("pause");
}