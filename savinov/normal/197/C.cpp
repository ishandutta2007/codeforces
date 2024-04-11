#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef char TYPE;

const TYPE INF = -1;

TYPE f(TYPE a,TYPE b)
{
    return max(a,b);
}

struct v
{
    v * l, * r;
    TYPE val;

    v(TYPE vr):l(0),r(0),val(vr){}

    v(v *l, v *r):l(l),r(r),val(INF)
    {
        val=f(val,l->val);
        val=f(val,r->val);
    }
};

v* build(TYPE a[],int tl,int tr)
{
    if (tl==tr) return new v(a[tl]);
    int m=(tl+tr)/2;
    return new v(build(a,tl,m),build(a,m+1,tr));
}

TYPE get_f(v * from,int tl, int tr, int l, int r)
{
    if (l>r) return INF;
    if (tl==l && r==tr) return from->val;

    int m=(tl+tr)/2;

    return f(get_f(from->l,tl,m,l,min(r,m)),get_f(from->r,m+1,tr,max(l,m+1),r));
}

void update (v* from,int tl, int tr,int pos,TYPE value)
{
    from->val=f(from->val,value);
    int m=(tl+tr)/2;
    if (pos<=m)
    {
        update(from->l,tl,m,pos,value);
    }
    else
    {
        update(from->r,m+1,tr,pos,value);
    }
}

int main()
{
    TYPE a[100000];
    char c;
    int i=0;
    while ((c=getchar())!='\n')
    {
        a[i]=c;
        i++;
    }
    int n=i;
    v *root = build(a,0,n-1);
    for (int i=0;i<n;i++)
    {
        if (a[i]>=get_f(root,0,n-1,i+1,n-1)) cout << a[i];
    }
    return 0;
}