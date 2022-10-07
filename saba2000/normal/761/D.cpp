#include<bits/stdc++.h>
using namespace std;
int n,l,r,a[100009],b[100009],c1[100009];
pair<int,int> c[100009];
string s;
int main()
{cin>>n>>l>>r;
for (int i=0; i<n; i++)
cin>>a[i];
for (int i=0; i<n; i++)
{cin>>c[i].first;
c[i].second=i;}
sort(c,c+n); int s=c[0].second,t=s;
b[s]=l; c1[s]=b[s]-a[s];
for (int i=1; i<n; i++)
{int t=c[i].second; s=c[i-1].second;
int p=a[t]+c1[s]+1;
if (p>r) {cout<<-1<<endl; return 0;}
else b[t]=max(p,l); c1[t]=b[t]-a[t];
}
for (int i=0; i<n; i++)
cout<<b[i]<<" ";
}