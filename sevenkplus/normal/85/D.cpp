#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int inf=1000000007;
class Splay
{
private:
    struct nd
    {
        ll s[5];int v;nd*c[2],*p;int sz;
        nd(int x,nd*n=0){s[0]=s[1]=s[2]=s[3]=s[4]=0;s[0]=v=x;sz=1;c[0]=c[1]=p=n;}
        void U()
        {
            sz=c[0]->sz+c[1]->sz+1;
            s[0]=s[1]=s[2]=s[3]=s[4]=0;
            for(int i=0;i<5;i++)s[i]+=c[0]->s[i];
            for(int i=0;i<5;i++)s[(i+c[0]->sz+1)%5]+=c[1]->s[i];
            s[(c[0]->sz)%5]+=v;
        }
        void D(){}
        void sc(nd*x,bool t){c[t]=x,x->p=this;}
        bool d(){return p->c[1]==this;}
        void out(){printf("%lld %lld %lld %lld %lld\n",s[0],s[1],s[2],s[3],s[4]);}
    }*h,*u;
    void rt(nd*x)
    {
        nd*y=x->p;bool d=x->d();
        y->D(),x->D();
        y->sc(x->c[!d],d),y->p->sc(x,y->d()),x->sc(y,!d);
        y->U();if(y==h)h=x;
    }
    void spl(nd*x,nd*y)
    {
        x->D();
        while(x->p!=y)
            if(x->p->p==y)rt(x);
            else(x->d()==x->p->d())?(rt(x->p),rt(x)):(rt(x),rt(x));
        x->U();
    }
    nd*slt(int x)
    {
        int r;nd*p=h;
        while(1)
        {
            p->D(),r=p->c[0]->sz;
            if(r==x)return p;
            p=p->c[r<x];
            if(x>r)x-=r+1;
        }
    }
    nd*get(int l,int r)
    {
        spl(slt(l),u),spl(slt(r),h);
        return h->c[1]->c[0];
    }
    int rnk(nd*x,int y)
    {
        if(x==u)return 0;
        if(x->v<y)return x->c[0]->sz+1+rnk(x->c[1],y);
        return rnk(x->c[0],y);
    }
public:
    Splay()
    {
        u=new nd(0);u->sz=0;
        h=new nd(0,u);nd*r=new nd(0,u);h->sc(r,1);
        u->v=h->v=-inf;r->v=inf;
        spl(r,u);
    }
    void add(int x)
    {
        int s=rnk(h,x)-1;
        get(s,s+1);
        nd*p=new nd(x,u);
        h->c[1]->sc(p,0);
        spl(p,u);
    }
    void del(int x)
    {
        int s=rnk(h,x);
        get(s-1,s+1);
        h->c[1]->sc(u,0);
        spl(h->c[1],u);
    }
    ll ask()
    {
        return get(0,h->sz-2+1)->s[2];
    }
}T;
int main()
{
    int _;scanf("%d",&_);
    while(_--)
    {
        char s[10];int x;
        scanf("%s%d",s,&x);
        if(s[0]=='a')T.add(x);else
        if(s[0]=='d')T.del(x);else
        if(s[0]=='s')printf("%I64d\n",T.ask());
    }
    return 0;
}