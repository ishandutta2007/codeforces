#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500009];
long long d[500009];
int nex[500009];
int main()
{cin>>n;
a[n+1]=1000000000000000000;
for (int i=1; i<=n; i++)
 {cin>>a[i];
d[i]=a[i];
}
for(int i=1; i<=n; i++)
nex[i]=i+1;
int q;
cin>>q;
while(q--)
{
long long f,s,t;
cin>>f;
if(f==1){cin>>s>>t;
int e=s;int u=0;
while(t>0){
if(u==1)e=nex[e];
//cout<<e<<" "<<t<<endl;
u=1;
int x=min(t,a[e]); a[e]-=x; t-=x;}
nex[s]=max(nex[s],e);
}
else{cin>>s;
//cout<<a[s]<<endl;
cout<<d[s]-a[s]<<endl;}
}


}