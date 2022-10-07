#include<bits/stdc++.h>
using namespace std;		
int n,b[200009],p[200009],f[200009],f1[200009],k,t,ans;
main()
{cin>>n;
for (int i=1; i<=n; i++)
cin>>p[i];
for (int i=1; i<=n; i++)
{cin>>b[i];
k+=b[i];
}
k++;
int r=1; int q=2,z=1;
while(z<=n)
{f[r]=1;
while(f[q]==1) q++;
if (f[p[r]]==1 && !(z==n && p[r]==1)) {r=q; ans++;} else
r=p[r];
z++;
}
//4 3 2 1

cout<<ans+k%2<<endl;
}