#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;

int v[N*4];
int a[N];

int build(int i, int l, int r)
{
    if (l==r)
    {
        v[i]=a[l];
        return 0;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    int c=build(i*2+1,mid+1,r);
    if (c==0) v[i]=(v[i*2]|v[i*2+1]); else v[i]=(v[i*2]^v[i*2+1]);
    return 1-c;
}

int update(int i, int l, int r, int x, int t)
{
    if (l==r) {v[i]=t; return 0;}
    int mid=(l+r)/2;
    int c;
    if (x<=mid) c=update(i*2,l,mid,x,t); else c=update(i*2+1,mid+1,r,x,t);
    if (c==0) v[i]=(v[i*2]|v[i*2+1]); else v[i]=(v[i*2]^v[i*2+1]);
    return 1-c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int p,k;
    cin>>p>>k;
    int n=(1<<p);
    for (int i=1; i<=n; i++)
        cin>>a[i];
    build(1,1,n);
    for (int i=1; i<=k; i++)
    {
        int l,r;
        cin>>l>>r;
        int c=update(1,1,n,l,r);
        cout<<v[1]<<endl;
    }
}