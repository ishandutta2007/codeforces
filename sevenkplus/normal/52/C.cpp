#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<sstream>
#include<cstdlib>
using namespace std;
typedef long long ll;
const ll inf=10000000000000000LL;
ll f[600000],g[600000];
int n,h=1;
void bt(int l,int r)
{
    if(l==r)
    {
        if(r<=n)
            scanf("%I64d",&f[l+r]);
        else
            f[l+r]=inf;
        return;
    }
    int m=(l+r)/2;
    bt(l,m);bt(m+1,r);
    f[l+r]=min(f[l+m],f[m+1+r]);
}
void add(int l,int r,ll a)
{
    f[l+r]+=a,g[l+r]+=a;
}
void upd(int l,int r)
{
    if(g[l+r])
    {
        int m=(l+r)/2;
        add(l,m,g[l+r]);
        add(m+1,r,g[l+r]);
        g[l+r]=0;
    }
}
void doo(int L,int R,int l,int r,int a)
{
    if(l<=L&&R<=r)
        add(L,R,a);
    else
    {
        int M=(L+R)/2;
        upd(L,R);
        if(l<=M)
            doo(L,M,l,r,a);
        if(M<r)
            doo(M+1,R,l,r,a);
        f[L+R]=min(f[L+M],f[M+1+R]);
    }
}
void doo(int l,int r,int a)
{
    doo(1,h,l,r,a);
}
ll ask(int L,int R,int l,int r)
{
    if(l<=L&&R<=r)
        return f[L+R];
    else
    {
        int M=(L+R)/2;
        upd(L,R);
        ll s=inf;
        if(l<=M)
            s=min(s,ask(L,M,l,r));
        if(M<r)
            s=min(s,ask(M+1,R,l,r));
        return s;
    }
}
ll ask(int l,int r)
{
    return ask(1,h,l,r);
}
int main()
{
    scanf("%d",&n);
    for(;h<n;h+=h);
    bt(1,h);
    int l,r,m,a;
    char s[100];
    scanf("%d",&m);
    gets(s);
    for(;m--;)
    {
        gets(s);
        stringstream in(s);
        in>>l>>r;
        l++,r++;
        if(in>>a)
        {
            if(l>r)
                doo(l,n,a),doo(1,r,a);
            else
                doo(l,r,a);
        }
        else
        {
            if(l>r)
                printf("%I64d\n",min(ask(l,n),ask(1,r)));
            else
                printf("%I64d\n",ask(l,r));
        }
    }
    return 0;
}