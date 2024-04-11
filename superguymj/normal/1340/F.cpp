#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
const int N=100005;
int n,m,k,a[N],ln,x,y,ql,qr;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

const LL b1=131,b2=233;
const LL m1=1000000007,m2=1000000009;
LL pw1[N],pw2[N],ipw1[N],ipw2[N];

struct str
{
	int len;
	LL h1,h2;

	void init(int x=0)
	{
		h1=h2=x,len=1;
		if(!x) len=0;
	}
} s1,s2;

str operator - (str a,str b)
{
	str c;
	c.len=a.len-b.len;
	c.h1=(a.h1-b.h1+m1)*ipw1[b.len]%m1;
	c.h2=(a.h2-b.h2+m2)*ipw2[b.len]%m2;
	return c;
}

str operator + (str a,str b)
{
	str c;
	c.len=a.len+b.len;
	c.h1=(a.h1+b.h1*pw1[a.len])%m1;
	c.h2=(a.h2+b.h2*pw2[a.len])%m2;
	return c;
}

bool operator == (str a,str b)
{
	return a.len==b.len && a.h1==b.h1 && a.h2==b.h2;
}

struct seg
{
	str L,R;
	bool tp=1;
	
	void init(int x)
	{
		if(x<0) L.init(-x),R.init();
		else R.init(x),L.init();
	}
} t[N<<2];

void merge(str &t1,str &t2,str a,str b,str c,str d)
{
	if(b.len<c.len) t1=a+(c-b),t2=d;
	else t1=a,t2=d+(b-c);
}

void calcL(int l,int r,int rt)
{
	if(l==r)
	{
		str tmp1,tmp2;
		if(t[rt].tp)
		{	
			merge(tmp1,tmp2,s1,s2,t[rt].L,t[rt].R);
			if(tmp1.len<=ln) s1=tmp1,s2=tmp2;
		}
		return;
	}
	str tmp1,tmp2;
	merge(tmp1,tmp2,s1,s2,t[lch].L,t[lch].R);
	if(!t[lch].tp || tmp1.len>=ln) calcL(l,mid,lch);
	else s1=tmp1,s2=tmp2,calcL(mid+1,r,rch);
}	

void calcR(int l,int r,int rt)
{
	if(l==r)
	{
		str tmp1,tmp2;
		if(t[rt].tp)
		{
			merge(tmp1,tmp2,s1,s2,t[rt].R,t[rt].L);
			if(tmp1.len<=ln) s1=tmp1,s2=tmp2;
		}
		return;
	}
	str tmp1,tmp2;
	merge(tmp1,tmp2,s1,s2,t[rch].R,t[rch].L);
	if(!t[rch].tp || tmp1.len>=ln) calcR(mid+1,r,rch);
	else s1=tmp1,s2=tmp2,calcR(l,mid,lch);
}	

seg pushup(int l,int r,int rt,seg t1,seg t2)
{
	seg ret;
	ret.L.init(),ret.R.init();

	if(t1.tp==0 || t2.tp==0)
	{
		ret.tp=0;
		return ret;
	}

	ret.tp=1;

	if(t1.R==t2.L)
	{
		ret.L=t1.L;
		ret.R=t2.R;
		return ret;
	}

	if(t1.R.len==t2.L.len)
	{
		ret.tp=0;
		return ret;
	}

	if(t1.R.len<t2.L.len)
	{
		ln=t1.R.len;
		s1.init(),s2.init();
		calcL(mid+1,r,rch);
		if(t1.R==s1)
		{
			ret.R=t2.R;
			ret.L=t1.L+(t2.L-s1);
		}
		else ret.tp=0;
	}
	else
	{
		ln=t2.L.len;
		s1.init(),s2.init();
		calcR(l,mid,lch);
		if(t2.L==s1)
		{
			ret.L=t1.L;
			ret.R=t2.R+(t1.R-s1);
		}
		else ret.tp=0;
	}
	return ret;
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt].init(a[l]);
		return;
	}
	build(l,mid,lch);
	build(mid+1,r,rch);
	t[rt]=pushup(l,r,rt,t[lch],t[rch]);
}

void change(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt].init(y);
		return;
	}
	if(x<=mid) change(l,mid,lch);
	else change(mid+1,r,rch);
	t[rt]=pushup(l,r,rt,t[lch],t[rch]);
}

LL getmi(LL a,LL x,LL mod)
{
	LL rt=1;
	while(x)
	{
		if(x&1) rt=rt*a%mod;
		a=a*a%mod,x>>=1;
	}
	return rt;
}

void init()
{
	pw1[0]=pw2[0]=ipw1[0]=ipw2[0]=1;
	rep(i,1,n)
	{
		pw1[i]=pw1[i-1]*b1%m1,pw2[i]=pw2[i-1]*b2%m2;
		ipw1[i]=getmi(pw1[i],m1-2,m1);
		ipw2[i]=getmi(pw2[i],m2-2,m2);
	}
	build(1,n,1);
}

seg query(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
		return t[rt];
	if(qr<=mid) return query(l,mid,lch);
	if(mid<ql) return query(mid+1,r,rch);
	return pushup(l,r,rt,query(l,mid,lch),query(mid+1,r,rch));
}

int main()
{
//	freopen("f.in","r",stdin);
//	freopen("f.out","w",stdout);
	n=getint(),k=getint();
	rep(i,1,n) a[i]=getint();
	init();
	m=getint();
	while(m--)
	{
		if(getint()==1)
		{
			x=getint(),y=getint();
			change(1,n,1);
		}
		else
		{
			ql=getint(),qr=getint();
			seg p=query(1,n,1);
			if(p.tp==0 || p.L.len || p.R.len) puts("No");
			else puts("Yes");
		}
	}
	return 0;
}