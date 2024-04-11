#include<bits/stdc++.h>
using namespace std;
int main()
{int n,m,k,a[10009];
cin>>n>>m>>k;
for (int i=1; i<=n; i++)
cin>>a[i];
for (int j=1; j<=n; j++)
if(m-j>=1 && a[m-j] && a[m-j]<=k){cout<<j*10<<endl; return 0;}
else 
if(m+j<=n && a[m+j] && a[m+j]<=k){cout<<j*10<<endl; return 0;}

}