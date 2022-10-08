#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define P 1000000009
struct nd
{
    int x,y,s,f,g;nd*le,*ri;
    nd(int _x,int _y);  
}*u,*h;
nd::nd(int _x,int _y):x(_x),y(_y),s(1),f(0),g(0),le(u),ri(u){}
void upd(nd*x)
{
    if(x==u)return;
    x->s=x->le->s+x->ri->s+1,
    x->f=x->le->g+x->ri->g,
    x->g=max(x->f,max(x->le->f+x->ri->g,x->ri->f+x->le->g)+1);
}
void spl(nd*x,int y,nd**le,nd**ri)
{
    if(x==u){*le=*ri=u;return;}
    if(x->x>y)spl(x->le,y,le,ri),x->le=*ri,*ri=x;
    else spl(x->ri,y,le,ri),x->ri=*le,*le=x;
    upd(x);
}
nd* mer(nd*x,nd*y)
{
    if(x==u)return y;
    if(y==u)return x;
    if(x->y>y->y){x->ri=mer(x->ri,y),upd(x);return x;}
    y->le=mer(x,y->le),upd(y);return y;
}
nd* ins(nd* x,nd* y)
{
    nd *le,*ri;
    spl(x,y->x,&le,&ri);
    return mer(le,mer(y,ri));
}
int main()
{
    int n,m;
    u=new nd(0,0),u->s=0,u->le=u->ri=u,u->f=-1,u->g=0,h=u;
    scanf("%d%d",&n,&m);int x,y;
    for(int i=0;i<m;i++)
        scanf("%d%d",&x,&y),h=ins(h,new nd(x,y));
    int pa,pb,pc,pd;
    scanf("%d%d%d%d",&pa,&pb,&pc,&pd);
    for(int i=m;i<n;i++)
        x=((ll)x*pa+pb)%P,y=((ll)y*pc+pd)%P,
        h=ins(h,new nd(x,y));
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&x,&y),--x;
        nd*le,*mi,*ri;
        spl(h,x,&le,&mi),spl(mi,y,&mi,&ri);
        printf("%d\n",mi->g);
        h=mer(le,mer(mi,ri));
    }
    return 0;
}