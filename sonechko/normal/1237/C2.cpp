#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;

int a[N],b[N],c[N],d[N];
int use[N];

bool cmp(int l, int r)
{
    if (a[l]!=a[r]) return (a[l]<a[r]);
    if (b[l]!=b[r]) return (b[l]<b[r]);
    if (c[l]!=c[r]) return (c[l]<c[r]);
    return (l<r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            d[i]=i;
        }
    sort(d+1,d+n+1,cmp);
    for (int i=2; i<=n; i++)
        if (a[d[i]]==a[d[i-1]]&&b[d[i]]==b[d[i-1]]&&use[d[i-1]]==0)
    {
        use[d[i-1]]=1;
        use[d[i]]=1;
        cout<<d[i-1]<<" "<<d[i]<<"\n";
    }
    int p=0;
    for (int i=1; i<=n; i++)
    if (use[d[i]]==0) {p++; d[p]=d[i];}
    n=p;
    for (int i=2; i<=n; i++)
        if (a[d[i]]==a[d[i-1]]&&use[d[i-1]]==0)
    {
        use[d[i-1]]=1;
        use[d[i]]=1;
        cout<<d[i-1]<<" "<<d[i]<<"\n";
    }
    p=0;
    for (int i=1; i<=n; i++)
    if (use[d[i]]==0) {p++; d[p]=d[i];}
    n=p;
    for (int i=2; i<=n; i+=2)
        cout<<d[i-1]<<" "<<d[i]<<"\n";
}