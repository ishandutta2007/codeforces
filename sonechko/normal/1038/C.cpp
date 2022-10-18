#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 1e5 + 11;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
        cin>>b[i];
    sort(b+1,b+n+1);
    int t=0;
    int k1=n,k2=n;
    ll ans=0;
    while (k1>0||k2>0)
    {
        if (t==0)
        {
            if (k2==0) {ans+=a[k1]; k1--;} else
            if (k1==0) {k2--;} else
            if (a[k1]>b[k2]) {ans+=a[k1]; k1--;} else
                {k2--;}
            t=1;
        } else
        {
            if (k1==0) {ans-=b[k2]; k2--;} else
            if (k2==0) {k1--;} else
            if (b[k2]>a[k1]) {ans-=b[k2]; k2--;} else
                {k1--;}
            t=0;
        }
    }
    cout<<ans;
}