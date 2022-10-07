#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int t[165432],n,k,q,a[165431],l,j,r[7],z,y;

main()
{cin>>n>>k>>q;
for (int i=1; i<=n; i++)
cin>>t[i];
for (int i=0; i<q; i++)
{cin>>l>>j;
if (l==1) {
y=0;
if (r[y]!=0)
for (int u=1; u<k; u++)
{if (t[r[u]]<t[r[y]] || r[u]==0 ) y=u;}
if(t[j]>t[r[y]] || r[y]==0) {r[y]=j;; } continue;}
z=0;
for (int u=0; u<k; u++)
if (r[u]==j) {cout<<"YES"<<endl; z=1; break;}
if (z==0) cout<<"NO"<<endl;
}
}