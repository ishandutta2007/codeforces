#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N = 2e5 + 11;
int a[N];

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=m; i++)
    {
        int k;
        cin>>k;
        int l=1,r=n;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (a[mid]>k) r=mid; else l=mid;
        }
        if (a[r]<=k) cout<<r<<" "; else
        if (a[l]<=k) cout<<l<<" "; else cout<<"0 ";
    }
}