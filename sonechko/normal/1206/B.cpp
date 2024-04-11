#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 11;

ll a[N];

int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll ans=0;
    int k1=0,k2=0,k3=0;
    for (int i=1; i<=n; i++)
        if (a[i]<0) {ans+=-a[i]-1; k1++;} else
        if (a[i]>0) {ans+=a[i]-1; k2++;} else k3++;
    if (k1%2==1&&k3>0) {ans+=1; k3--; k1++;}
    if (k1%2==1) {ans+=2; k1--; k2++;}
    ans+=k3;
    cout<<ans;
}