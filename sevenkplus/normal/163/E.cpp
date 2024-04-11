#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000010
int n,m,he[N],ad[N],ne[N],fi[N],fo[N];char s[N];int p[N][26],Lp=1,e[N],fl[N],r[N];
int q[N];
void ff()
{
    int le=0,ri=1;q[0]=1;
    while(le<ri)
    {
        int x=q[le++];
        for(int i=0;i<26;i++)if(p[x][i])
        {
            int w=fl[x];
            while(w&&!p[w][i])w=fl[w];
            if(!w)fl[p[x][i]]=1;
            else fl[p[x][i]]=p[w][i];
            q[ri++]=p[x][i];
        }
    }
}
void addE(int x,int y)
{
    static int t=0;
    ++t,ne[t]=he[x],he[x]=t,ad[t]=y;
}
void ff(int x)
{
    static int t=0;
    fi[x]=++t;
    for(int p=he[x];p;p=ne[p])ff(ad[p]);
    //for(int i=0;i<26;i++)if(p[x][i])ff(p[x][i]);
    fo[x]=++t;
}
int f[N*8],f0[N*2];
void blt(int p,int l,int r)
{
    if(l==r){f[p]=f0[l];return;}
    int mid=(l+r)/2;
    blt(p*2,l,mid),blt(p*2+1,mid+1,r);
    f[p]=f[p*2]+f[p*2+1];
}
int ask(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)return f[p];
    int mid=(l+r)/2,S=0;
    if(L<=mid)S+=ask(p*2,l,mid,L,R);
    if(mid+1<=R)S+=ask(p*2+1,mid+1,r,L,R);
    return S;
}
void add(int p,int l,int r,int x)
{
    if(l==r){f[p]=f0[l];return;}
    int mid=(l+r)/2;
    if(x<=mid)add(p*2,l,mid,x);
    else add(p*2+1,mid+1,r,x);
    f[p]=f[p*2]+f[p*2+1];
}
void del(int p,int l,int r,int x)
{
    if(l==r){f[p]=0;return;}
    int mid=(l+r)/2;
    if(x<=mid)del(p*2,l,mid,x);
    else del(p*2+1,mid+1,r,x);
    f[p]=f[p*2]+f[p*2+1];
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);int l=strlen(s),w=1;
        for(int j=0;j<l;j++)
        {
            if(!p[w][s[j]-'a'])p[w][s[j]-'a']=++Lp;
            w=p[w][s[j]-'a'];
        }
        e[i]=w,r[w]++;
    }
    ff();
    for(int i=2;i<=Lp;i++)addE(fl[i],i);
    ff(1);
    for(int i=1;i<=Lp;i++)
        f0[fi[i]]=r[i],f0[fo[i]]=-r[i];
    blt(1,1,Lp*2);
    while(m--)
    {
        scanf("%s",s);int p2=strlen(s),x=0;
        if(s[0]=='+')
        {
            for(int i=1;i<p2;i++)x*=10,x+=s[i]-'0';
            add(1,1,Lp*2,fi[e[x-1]]),add(1,1,Lp*2,fo[e[x-1]]);
        }else
        if(s[0]=='-')
        {
            for(int i=1;i<p2;i++)x*=10,x+=s[i]-'0';
            del(1,1,Lp*2,fi[e[x-1]]),del(1,1,Lp*2,fo[e[x-1]]);
        }else
        {
            int w=1,S=0;
            for(int i=1;i<p2;i++)
            {
                while(w!=1&&!p[w][s[i]-'a'])w=fl[w];
                if(p[w][s[i]-'a'])w=p[w][s[i]-'a'];
                S+=ask(1,1,Lp*2,1,fi[w]);
            }
            printf("%d\n",S);
        }
    }
    return 0;
}