#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
struct node
{
    int l,r,ans,lb,rb;
}seg[MAXN*4];
struct save
{
    int ans,lb,rb;
};
char str[MAXN];
int q;
void build(int k,int l,int r)
{
    seg[k].l=l;
    seg[k].r=r;
    if(l==r)
    {
        seg[k].ans=0;
        if(str[l-1]=='(')
        {
            seg[k].lb=1;
            seg[k].rb=0;
        }
        else
        {
            seg[k].lb=0;
            seg[k].rb=1;
        }
        return;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    int x=min(seg[k*2].lb,seg[k*2+1].rb);
    seg[k].ans=seg[k*2].ans+seg[k*2+1].ans+x;
    seg[k].lb=seg[k*2].lb+seg[k*2+1].lb-x;
    seg[k].rb=seg[k*2].rb+seg[k*2+1].rb-x;
}
save query(int k,int l,int r)
{
    if(seg[k].l>r||seg[k].r<l) return (save){0,0,0};
    if(seg[k].l>=l&&seg[k].r<=r)
        return (save){seg[k].ans,seg[k].lb,seg[k].rb};
    save x=query(k*2,l,r);
    save y=query(k*2+1,l,r);
    int a,b,c;
    int p=min(x.lb,y.rb);
    a=x.ans+y.ans+p;
    b=x.lb+y.lb-p;
    c=x.rb+y.rb-p;
    return (save){a,b,c};
}
int main()
{
    scanf("%s",str);
    int n=strlen(str);
    build(1,1,n);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",2*query(1,x,y).ans);
    }
    return 0;
}