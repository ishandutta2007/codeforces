#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,ans=1000000000;
int main()
{cin>>a>>b>>c>>d;
for (int i=0; i<=1000; i++)
for (int j=0; j<=1000; j++)
if (b+i*a==d+j*c) ans=min(ans,b+i*a);
if (ans==1000000000) cout<<-1<<endl;
else cout<<ans<<endl;
return 0;
}