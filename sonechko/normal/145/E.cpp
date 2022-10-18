#include<bits/stdc++.h>
using namespace std;



const int N = 1e6 + 11;

int a[N];
int k0[N*4],k1[N*4],k01[N*4],k10[N*4],w[N*4];

void build(int i, int l, int r)
{
    if (l==r)
    {
        if (a[l]==0) k0[i]=1; else k1[i]=1;
        k01[i]=1;
        k10[i]=1;
    //cout<<l<<".."<<r<<" = "<<k0[i]<<" "<<k1[i]<<" "<<k01[i]<<" "<<k10[i]<<endl;
        return;
    }
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    k0[i]=k0[i+i]+k0[i+i+1];
    k1[i]=k1[i+i]+k1[i+i+1];
    k01[i]=max(k01[i+i]+k1[i+i+1],k0[i+i]+k01[i+i+1]);
    k10[i]=max(k10[i+i]+k0[i+i+1],k1[i+i]+k10[i+i+1]);
    //cout<<l<<".."<<r<<" = "<<k0[i]<<" "<<k1[i]<<" "<<k01[i]<<" "<<k10[i]<<endl;
}

void push(int i)
{
    if (w[i]==0) return;
    swap(k0[i+i],k1[i+i]);
    swap(k01[i+i],k10[i+i]);
    swap(k0[i+i+1],k1[i+i+1]);
    swap(k01[i+i+1],k10[i+i+1]);
    w[i+i]^=1;
    w[i+i+1]^=1;
    w[i]=0;
}

void update(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr)
    {
        swap(k0[i],k1[i]);
        swap(k01[i],k10[i]);
        w[i]^=1;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i+i,l,mid,tl,tr);
    update(i+i+1,mid+1,r,tl,tr);
    k0[i]=k0[i+i]+k0[i+i+1];
    k1[i]=k1[i+i]+k1[i+i+1];
    k01[i]=max(k01[i+i]+k1[i+i+1],k0[i+i]+k01[i+i+1]);
    k10[i]=max(k10[i+i]+k0[i+i+1],k1[i+i]+k10[i+i+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s="."+s;
    for (int j=1; j<=n; j++)
        if (s[j]=='4') a[j]=0; else a[j]=1;
    build(1,1,n);
    for (int i=1; i<=m; i++)
    {
        string s;
        cin>>s;
        if (s[0]=='s')
        {
            int l,r;
            cin>>l>>r;
            update(1,1,n,l,r);
        } else
        {
            cout<<k01[1]<<"\n";
        }
    }
}