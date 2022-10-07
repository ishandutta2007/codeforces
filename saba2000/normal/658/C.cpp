#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

main()
{int n,d,h;
cin>>n>>d>>h;

if (d-h>h || d==1 && n>2) {cout<<-1<<endl; return 0;}
if (d==h)
{for (int i=2; i<=h+1; i++)
cout<<i<<" "<<i-1<<endl;
for (int i=h+2; i<=n; i++)
cout<<h<<" "<<i<<endl;
return 0;
}
for (int i=2; i<=h+1; i++)
cout<<i<<" "<<i-1<<endl;
for (int i=h+2; i<=d+1; i++)
if (i==h+2) cout<<i<<" "<<i-1-h<<endl;
else cout<<i<<" "<<i-1<<endl;
for (int i=d+2; i<=n; i++)
cout<<1<<" "<<i<<endl;


}