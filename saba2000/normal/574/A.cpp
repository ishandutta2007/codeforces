#include<algorithm>
#include<iostream>
using namespace std;
int n,a[109],d,p,k,ans;
main()
{cin>>n>>d;
for (int i=1; i<n; i++)
cin>>a[i];
while(1)
{p=d; k=0;
for (int i=1; i<n; i++)
if (a[i]>=p) {p=a[i]; k=i;}
if (k==0) break;
else{d++; a[k]--; ans++;}
}
cout<<ans<<endl;
}