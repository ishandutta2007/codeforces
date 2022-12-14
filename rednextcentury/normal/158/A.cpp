# include <algorithm>
# include <iostream>
using namespace std;
int a[10000];
int main ()
{
long long n,m,ans=0;
cin>>n>>m;
for (int i=0;i<n;i++)
    cin>>a[i];
sort (a,a+n);
long long s=a[n-(m)];

for (int i=0;i<n;i++)
{
    if (a[i]>=s && a[i]>0)
        ans++;



}
cout<<ans<<endl;

}