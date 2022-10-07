#include<iostream>
using namespace std;
int m,p,ans;
main()
{cin>>m;

for (int i=1; i<=10*m; i++)
{p=0;
for (int j=5; j<=400000; j*=5)
p+=i/j;
if (p==m) ans++;
}
cout<<ans<<endl;
for (int i=1; i<=10*m; i++)
{p=0;
for (int j=5; j<=400000; j*=5)
p+=i/j;
if (p==m) cout<<i<<" ";
}
cout<<endl;
}