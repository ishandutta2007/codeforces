#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int s[N*4];

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {s[i]+=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i+i,l,mid,x,t); else update(i+i+1,mid+1,r,x,t);
    s[i]=s[i+i]+s[i+i+1];
}

int get(int i, int l, int r, int p)
{
    if (l==r) return l;
    int mid=(l+r)/2;
    if (s[i+i]>=p) return get(i+i,l,mid,p);
    return get(i+i+1,mid+1,r,p-s[i+i]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    int ks=0;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        ks++;
        update(1,1,n,x,1);
    }
    for (int i=1; i<=q; i++)
    {
        int x;
        cin>>x;
        if (x>0)
        {
            ks++;
            update(1,1,n,x,1);
        } else
        {
            ks--;
            x=abs(x);
            int y=get(1,1,n,x);
            update(1,1,n,y,-1);
        }
    }
    if (ks==0) cout<<0; else cout<<get(1,1,n,1);
}