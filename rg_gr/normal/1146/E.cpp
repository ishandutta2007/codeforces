#include <stdio.h>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
#define int long long
const int mod = 571373;
int qp(int x,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=res*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return res;
}
#define Mod int
Mod a[400005<<2],sum[400005<<2],tag[400005<<2],charm[400005<<2];
inline void pushdown(int o,int l,int r)
{
	if(l==r)
	{
		sum[o]=sum[o]*tag[o]+charm[o];
		tag[o]=1,charm[o]=0;
		return;
	}
	int lc=o<<1,rc=lc^1;
	tag[lc]*=tag[o],charm[lc]*=tag[o],charm[lc]+=charm[o];
	tag[rc]*=tag[o],charm[rc]*=tag[o],charm[rc]+=charm[o];
	tag[o]=1,charm[o]=0;
	//maintain(lc,l,l+r>>1);
	//maintain(rc,(l+r>>1)+1,r);
	//maintain(o,l,r);
}
int n;
inline void maintain(int o,int l,int r)
{
	if(l==r)
	{
		sum[o]=sum[o]*tag[o]+charm[o];
		charm[o]=0,tag[o]=1;
		return;
	}
	sum[o]=(sum[o<<1]+sum[o<<1|1])*tag[o]+charm[o]*(r-l+1);
	//pushdown(o,l,r);
}
void mul(int o,int l,int r,int L,int R,Mod x)
{
    if(L>R)L^=R^=L^=R;
	if(L<=l&&r<=R)
	{
		tag[o]*=x;
		charm[o]*=x;
		maintain(o,l,r);
		return;
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	if(L<=m)mul(o<<1,l,m,L,R,x);else maintain(o<<1,l,m);
	if(m<R)mul(o<<1|1,m+1,r,L,R,x);else maintain(o<<1|1,m+1,r);
	maintain(o,l,r);
}
Mod query(int o,int l,int r,int L,int R)
{
    if(L>R)L^=R^=L^=R;
	if(L<=l&&r<=R)
	{
		maintain(o,l,r);
		return sum[o];
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	Mod ans=0;
	if(L<=m)ans+=query(o<<1,l,m,L,R);else maintain(o<<1,l,m);
	if(m<R)ans+=query(o<<1|1,m+1,r,L,R);else maintain(o<<1|1,m+1,r);
	maintain(o,l,r);
	return ans;
}
void add(int o,int l,int r,int L,int R,int x)
{
    if(L>R)L^=R^=L^=R;
	if(L<=l&&r<=R)
	{
		charm[o]+=x;
		maintain(o,l,r);
		return;
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	if(L<=m)add(o<<1,l,m,L,R,x);else maintain(o<<1,l,m);
	if(m<R)add(o<<1|1,m+1,r,L,R,x);else maintain(o<<1|1,m+1,r);
	maintain(o,l,r);
}
inline int getcHar()
{
    char c=getchar();
    while(c!='<'&&c!='>')c=getchar();
    return c=='>';
}
int qwqwq[100005<<1];
signed main()
{
	int N=200001,q=read(),m=read(),n=1;
	for(int i=0;i<q;i++)qwqwq[i]=read();
	while(n<N)n<<=1;
	for(int i=n,j=-100000;i<N+n;i++,j++)sum[i]=1;
	for(int i=1;i<n+n;i++)tag[i]=1,charm[i]=0;
	for(int i=n-1;i>=1;i--)sum[i]=sum[i<<1]+sum[i<<1|1];
	while(m--)
	{
        int qq=getcHar(),x=read();//printf("Qq %lld\n",qq);
        if(qq==1)
        {
            //if(x>=0)
            {
                if(x>=0)
                {
                    mul(1,1,n,1,100000-x,0);
                    add(1,1,n,1,100000-x,1);
                    mul(1,1,n,100002+x,200001,0);
                    add(1,1,n,100002+x,200001,-1);
                }
                else
                {
                    mul(1,1,n,100001+x+1,100001-x-1,-1);
                    mul(1,1,n,1,100001+x,0);
                    add(1,1,n,1,100001+x,1);
                    mul(1,1,n,100001-x,200001,0);
                    add(1,1,n,100001-x,200001,-1);
                }
                /*mul(1,1,n,100001-x,100001+x,-1);
                //x=x>0?x:-x;
                mul(1,1,n,1,100000-x,0);
                add(1,1,n,1,100000-x,1);
                mul(1,1,n,100002+x,200001,0);
                add(1,1,n,100002+x,200001,-1);*/
                
            }
        }
        else
        {
            if(x<=0)
            {
                mul(1,1,n,1,100000+x,0);
                add(1,1,n,1,100000+x,-1);
                mul(1,1,n,100002-x,200001,0);
                add(1,1,n,100002-x,200001,1);
            }
            else
            {
                mul(1,1,n,100001-x+1,100001+x-1,-1);
                mul(1,1,n,1,100000-x+1,0);
                add(1,1,n,1,100000-x+1,-1);
                mul(1,1,n,100002+x-1,200001,0);
                add(1,1,n,100002+x-1,200001,1);
            }
        }        }
    //puts("fix");
    for(int i=0;i<q;i++)printf("%lld ",qwqwq[i]*query(1,1,n,qwqwq[i]+100001,qwqwq[i]+100001));
		//int op=read(),x=read(),y=read(),k;
		///if(op!=3)k=read();
		//if(op==1)mul(1,1,n,x,y,k);
		//else if(op==2)add(1,1,n,x,y,k);
		//else printf("%lld\n",query(1,1,n,x,y).x);
		//for(int i=1;i<=n;i++)printf("%lld ",query(1,1,n,i,i).x);puts("");
	
}