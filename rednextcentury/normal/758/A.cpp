#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[10000];
int main()
{
    fast_io
    int n;
    cin>>n;
    int mx=0,s=0;
    for (int i=0;i<n;i++)
        cin>>a[i],s+=a[i],mx=max(mx,a[i]);
    cout<<mx*n-s<<endl;
}