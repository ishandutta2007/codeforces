#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max qwqwqqwqwwq
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b)
{
    return a<b?a:b;
}
int n,k;
struct Node{
    int l,r,tag,min;
    Node *lc,*rc;
}*root;
int Max[22][1000005];
inline int max(int a,int b)
{
    return a<b?a:b;
}
inline int Query(int l,int r)
{
    int k=log2(r-l+1); 
    return max(Max[k][l],Max[k][r-(1<<k)+1]);
}
inline int qwq(int l,int r)
{
    if(r-l+1>=n)return Query(1,n);
    int bl=(l-1)/n+1,br=(r-1)/n+1;
    int ql=(l-1)%n+1,qr=(r-1)%n+1;
    if(bl==br)return Query(ql,qr);
    return max(Query(ql,n),Query(1,qr));
}
Node* newNode(Node* p ,int l,int r)
{
    Node* o;
    o=new Node();
    o->l=l,o->r=r,o->lc=o->rc=NULL;
    o->tag=0;
    #define printf
    o->min=qwq(l,r);
    printf("\n[%lld %lld] : %lld qwq\n",l,r,o->min);
    return o;
}
inline void pushdown(Node* o)
{
    o->lc->tag=o->rc->tag=o->lc->min=o->rc->min=o->tag;
    o->tag=0;
}
inline void maintain(Node* o)
{
    o->min=max(o->lc->min,o->rc->min);
}
void modify(Node*o,int L,int R,int l,int r,int v)
{
    if(o==NULL)o=newNode(o,L,R);
    printf("\nmod %lld %lld %lld %lld %lld\n",L,R,l,r,v);
    if(l<=L&&R<=r)
    {
        o->tag=v;
        o->min=v;
        return;
    }
    int M=L+R>>1;
    if(o->lc==NULL)o->lc=newNode(o->lc,L,M);
    if(o->rc==NULL)o->rc=newNode(o->rc,M+1,R);
    if(o->tag)pushdown(o);
    if(l<=M)modify(o->lc,L,M,l,r,v);
    if(M<r)modify(o->rc,M+1,R,l,r,v);
    maintain(o);
}
int query(Node *o,int L,int R,int l,int r)
{
    if(o==NULL)o=newNode(o,L,R);
    //
    printf("\nql %lld %lld %lld %lld\n",L,R,l,r);
    if(l<=L&&R<=r)
    {
        //if(o==NULL)puts("psd");
        return o->min;
    }
    if(o->tag)return o->tag;
    //return o->min;
    int M=L+R>>1;
    int ans=0x3f3f3f3f;
    if(l<=M)ans=max(ans,query(o->lc,L,M,l,r));
    if(M<r)ans=max(ans,query(o->rc,M+1,R,l,r));
    return ans;
}
#undef printf
signed main()
{
    n=read(),k=read()*n;
    for(int i=1;i<=n;i++)Max[0][i]=read();
    int m=read();
    for(int j=1;j<=21;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            Max[j][i]=max(Max[j-1][i],Max[j-1][i+(1<<(j-1))]);
    root=newNode(root,1,k);
    while(m--)
    {
        int op=read(),x=read(),y=read();
        if(op==1)
        {
            int v=read();
            modify(root,1,k,x,y,v);
        }
        else printf("%d\n",query(root,1,k,x,y));
    }
}//qwqw