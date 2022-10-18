#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define int long long
#define ll long long
#define sqr(a) ((a)*(a))
#define ld long double
const int N = 2e5 + 11;
int a[N],b[N];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            b[i]=n*2;
        }
    int k=-1;
    for (int i=1; i<=n; i++)
    {
        if (a[i]==0) k=i;
        if (k!=-1) b[i]=i-k;
    }
    k=-1;
    for (int i=n; i>=1; i--)
    {
        if (a[i]==0) k=i;
        if (k!=-1) b[i]=min(b[i],k-i);
    }
    for (int i=1; i<=n; i++)
        cout<<b[i]<<" ";
}