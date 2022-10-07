#include<bits/stdc++.h>
using namespace std;
int n,a[300009],ans,ans1;
int main()
{cin>>n;for (int i=0; i<n; i++) cin>>a[i]; sort(a,a+n);
ans=a[1]-a[0]; ans1=1;
for (int i=1; i<n-1; i++)
if (a[i+1]-a[i]==ans) ans1++;
else if (a[i+1]-a[i]<ans) {ans=a[i+1]-a[i]; ans1=1;}
cout<<ans<<" "<<ans1<<endl;
}