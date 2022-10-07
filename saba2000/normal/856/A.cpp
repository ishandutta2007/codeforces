#include<bits/stdc++.h>
using namespace std;
int f[1000009];
int a[109];
main()
{
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    for (int i=0; i<n; i++)
    for (int j=i+1; j<n; j++){
        f[a[j]-a[i]]=t+1;
        //cout<<a[j]-a[i]<<endl;
        }
    int flag=0;
    for(int i=1; i<=10000; i++){flag=0;
        for(int j=i; j<=i*(n-1); j+=i)
    if(f[j]==t+1) {flag=1; //cout<<i<<" "<<j<<" "<<f[j]<<endl;
    break;}
   // cout<<i<<" "<<flag<<endl;
    if(flag==0) {cout<<"YES"<<endl;
     for(int j=1; j<=1+(n-1)*i; j+=i)
        cout<<j<<" ";
        cout<<endl;
     break;}
}
}
}