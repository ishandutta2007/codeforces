#include <iostream>
using namespace std;
int n,a,b,m,ans;
main()
{cin>>n>>m;
for(int i=0; i<n; i++)
for(int j=0; j<m; j++)
{cin>>a>>b;
if(a+b>0) ans++;
}
cout<<ans<<endl;
}