#include<bits/stdc++.h>
using namespace std;
int n,a[309],k,f[309],l=0;
int main()
{cin>>n>>k;for (int i=0; i<k; i++) cin>>a[i]; 
for (int i=0; i<k; i++)
{int p=(a[i])%(n-i); 
for (l; 1; l=(l+1)%n){
if (f[l]==0) {if (p==0) break; p--; }}
cout<<l+1<<" "; f[l]=1; l=(l+1)%n;
}


}