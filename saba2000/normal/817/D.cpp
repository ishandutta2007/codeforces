#include<bits/stdc++.h>
using namespace std;
long long a[1000009],n;
long long fbl[1000009],fbr[1000009],fsl[1000009],fsr[1000009];
main()

{cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
stack<int> S;
for (int i=0; i<n; i++)
{while(S.size() && a[S.top()]<=a[i])  S.pop();
if(S.size()==0) fbl[i]=-1;
else fbl[i]=S.top();
S.push(i);} while(S.size()) S.pop();
for (int i=n-1; i>=0; i--)
{while(S.size() && a[S.top()]<a[i])  S.pop();
if(S.size()==0) fbr[i]=n;
else fbr[i]=S.top();
S.push(i);}  while(S.size()) S.pop();
for (int i=0; i<n; i++)
{while(S.size() && a[S.top()]>=a[i])  S.pop();
if(S.size()==0) fsl[i]=-1;
else fsl[i]=S.top();
S.push(i);}  while(S.size()) S.pop();
for (int i=n-1; i>=0; i--)
{while(S.size() && a[S.top()]>a[i])  S.pop();
if(S.size()==0) fsr[i]=n;
else fsr[i]=S.top();
S.push(i);}long long ans=0;
for(int i=0; i<n; i++)
{ans+=a[i]*((i-fbl[i])*(fbr[i]-i)-(i-fsl[i])*(fsr[i]-i));
//cout<<fbl[i]<<" "<<fbr[i]<<" "<<fsl[i]<<" "<<fsr[i]<<endl;
}
cout<<ans<<endl;
}