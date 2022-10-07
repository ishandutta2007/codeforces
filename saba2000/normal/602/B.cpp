#include <iostream>
using namespace std;
int n,a[1000000],l=1,k=1,x=-1,ans;
main()
{
cin>>n>>a[0];
for (int i=1; i<n; i++)
{cin>>a[i];
if (a[i]==a[i-1]) {k++; l++;continue;}
if (a[i]==x) {l++; k=1; x=a[i-1];continue;}
if (a[i]==a[i-1]+1 || a[i]==a[i-1]-1) {ans=max(l,ans); l=k+1; k=1; x=a[i-1]; continue;}
ans=max(l,ans);
k=1; x=-1; l=1;

}
cout<<max(ans,l)<<endl;
}