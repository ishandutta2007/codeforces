#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{int n,k;
pair <int,int> a[200];
cin>>n>>k; for (int i=0; i<n; i++) {cin>>a[i].first; a[i].second=i+1;}
sort (a,a+n); int i;
for (i=0; i<n; i++)
{k-=a[i].first; if (a[i+1].first>k) break;} if (k<0) i--; if (i==n) i--;cout<<i+1<<endl;
for (int j=0; j<=i; j++)
cout<<a[j].second<<" ";
return 0;
}