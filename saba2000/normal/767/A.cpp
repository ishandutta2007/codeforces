#include<bits/stdc++.h>
using namespace std;
int n,a[1000009],p;
int main()
{cin>>n; int b=n;
for (int i=0; i<n; i++)
{cin>>p; a[p]=1;
while(a[b]==1) {cout<<b<<" "; b--;}
cout<<endl;
}
}