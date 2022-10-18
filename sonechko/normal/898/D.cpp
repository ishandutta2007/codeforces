#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
int v[N*4];
int a[N];
void update(int i, int l, int r, int x, int t)
{
    if (l==r) {v[i]=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i*2,l,mid,x,t); else update(i*2+1,mid+1,r,x,t);
    v[i]=v[i*2]+v[i*2+1];
}
int sum(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    return sum(i*2,l,mid,tl,tr)+sum(i*2+1,mid+1,r,tl,tr);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
        update(1,1,n,i,1);
    for (int i=1; i<=n; i++)
        if (sum(1,1,n,i,i)==1)
    {
        int l=i,r=n;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (a[mid]-a[i]<m) l=mid; else r=mid;
        }
        if (a[r]-a[i]<m) l=r;
        int ss=sum(1,1,n,i,l);
        while (ss>=k)
        {
            update(1,1,n,l,0);
            l--;
            ss--;
        }
    }
    cout<<n-v[1]<<endl;
}