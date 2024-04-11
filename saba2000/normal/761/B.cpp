#include<bits/stdc++.h>
using namespace std;
int n,l,a[100],b[100],c[100];
int main()
{cin>>n>>l; int p=0;
for (int i=0; i<n; i++)
{cin>>a[i];
c[a[i]]=1;
}
for (int i=0; i<n; i++)
cin>>b[i];
for (int i=0; i<l; i++)
{int d=1; p=0;
for (int j=0; j<n; j++){
if (c[(i+b[j])%l]==0) {d=0; break;}
p+=b[j];
}
if (d==1) {cout<<"YES"<<endl; return 0;}
}
cout<<"NO"<<endl;
}