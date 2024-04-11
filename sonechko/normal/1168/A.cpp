#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;

int n,m;
int a[N];

bool good(int x)
{
    int p=0;
    for (int i=1; i<=n; i++)
    {
        if (a[i]>=p)
        {
            int c=m-a[i]+p;
            if (c>x) p=a[i];
        } else
        {
            int c=p-a[i];
            if (c>x) return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int l=0,r=m;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) cout<<l<<endl; else cout<<r<<endl;
}