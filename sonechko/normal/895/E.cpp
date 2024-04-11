#include<bits/stdc++.h>
using namespace std;
#define ld double

const int N = 1e5 + 11;

ld w1[N*4],w2[N*4],v[N*4],a[N];
inline void push(int i, int l, int r, int mid)
{
    w1[i*2]*=w1[i];
    w2[i*2]*=w1[i];
    w2[i*2]+=w2[i];
    v[i*2]=v[i*2]*w1[i]+w2[i]*(mid-l+1);

    w1[i*2+1]*=w1[i];
    w2[i*2+1]*=w1[i];
    w2[i*2+1]+=w2[i];
    v[i*2+1]=v[i*2+1]*w1[i]+w2[i]*(r-mid);

    w1[i]=1;
    w2[i]=0;
}
void update(int i, int l, int r, int tl, int tr, ld xx, ld pp)
{
    if (tl<=l&&r<=tr) {w1[i]*=xx; w2[i]=w2[i]*xx+pp; v[i]=v[i]*xx+(r-l+1)*pp; return;}
    if (tl>r||tr<l) return;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    update(i*2,l,mid,tl,tr,xx,pp);
    update(i*2+1,mid+1,r,tl,tr,xx,pp);
    v[i]=v[i*2]+v[i*2+1];
}
ld sum(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    return sum(i*2,l,mid,tl,tr)+sum(i*2+1,mid+1,r,tl,tr);
}
void build(int i, int l, int r)
{
    w1[i]=1;
    w2[i]=0;
    if (l==r) {v[i]=a[l]; return;}
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    v[i]=v[i*2]+v[i*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    build(1,1,n);
    cout.precision(6);
    cout<<fixed;
    for (int jj=1; jj<=q; jj++)
    {
        int ks;
        cin>>ks;
        if (ks==1)
        {
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            ld mat1=sum(1,1,n,l1,r1)/(r1-l1+1);
            ld mat2=sum(1,1,n,l2,r2)/(r2-l2+1);
            update(1,1,n,l1,r1,(double)(r1-l1)/(r1-l1+1),mat2/(r1-l1+1));
            update(1,1,n,l2,r2,(double)(r2-l2)/(r2-l2+1),mat1/(r2-l2+1));
        } else
        {
            int l,r;
            cin>>l>>r;
            cout<<sum(1,1,n,l,r)<<"\n";
        }
    }


}