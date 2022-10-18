#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int a[N],n,m;
bool good(int l)
{
    int k=1,kol=0;
    for (int i=n; i>=k; i--)
    {
        if (a[i]+a[k]<=l) k++;
        kol++;
    }
    if (kol<=m) return true;
    return false;
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int l=a[n],r=2000000;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) cout<<l<<endl; else cout<<r<<endl;
}