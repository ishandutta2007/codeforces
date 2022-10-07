#include<bits/stdc++.h>
using namespace std;
main()
{int a[100009],n;
cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
sort(a,a+n);
long long t=0,g=0,w=0;
while(a[t]==a[0] && t<n) t++;
while(a[t+g]==a[t] && t+g<n) g++;
while(a[t+g+w]==a[t+g] && t+g+w<n) w++;
if(t>=3){cout<<t*(t-1)*(t-2)/6<<endl; return 0;}
if(t==2){cout<<g<<endl; return 0;}
if(g>=2) cout<<g*(g-1)/2<<endl;
else cout<<w<<endl;
}