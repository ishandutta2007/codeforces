#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#pragma GCC optimize(3)
#pragma GCC optimize("-O3")

#pragma G++ optimize(3)
#pragma G++ optimize("-O3")

using namespace std;

#define REP(v,a,b) for ((v)=(a);(v)<=(b);(v)++)
#define REPD(v,a,b) for ((v)=(a);(v)>=(b);(v)--)
#define REPS(v,a,b,s) for ((v)=(a);(v)<=(b);(v)+=(s))
#define REPDS(v,a,b,s) for ((v)=(a);(v)>=(b);(v)-=(s))
#define REPL(v,a,b) for ((v)=(a);(v)<=(b);(v)<<=1)
#define REPR(v,a,b) for ((v)=(a);(v)>=(b);(v)>>=1)
#define REPIF(v,a,b) for ((v)=(a);(b);(v)++)
#define REPIFD(v,a,b) for ((v)=(a);(b);(v)--)
#define REPIFS(v,a,b,s) for ((v)=(a);(b);(v)+=(s))
#define REPIFDS(v,a,b,s) for ((v)=(a);(b);(v)-=(s))
#define REPIFL(v,a,b) for ((v)=(a);(b);(v)<<=1)
#define REPIFR(v,a,b) for ((v)=(a);(b);(v)>>=1)

const int maxn=3e5;

const long long mod=998244353;
const long long inv2=499122177;
const int g=3;

typedef int coefficients[maxn];

inline int __usr_clz (int v)
{
	return v<2?v+1:1<<(33-__builtin_clz(v-1));
}

inline int __usr_fpw (int p,int e)
{
	if (e==0)
		return 1;
	long long ret=__usr_fpw(p,e>>1);
	ret=ret*ret%mod;
	if (e&1)
		ret=ret*p%mod;
	return ret;
}

inline int __usr_inv (int p)
{
	return __usr_fpw(p,mod-2);
}

inline void read(int &x)
{
	static char c;
	static bool neg;
	x=0;
	c=getchar();
	neg=0;
	while (c!='-'&&(c<'0'||c>'9'))
		c=getchar();
	if (c=='-')
	{
		neg=1;
		while (c<'0'||c>'9')
			c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}

inline void write(int x,int endl=0)
{
	static char s[25];
	static int i,j;
	i=0;
	s[i]=0+'0';
	while (x)
	{
		s[i]=x%10+'0';
		i++;
		x/=10;
	}
	if (i==0)
		i++;
	s[i]=0;
	if (endl)
	{
		for (j=0;j+j+1<i;j++)
			s[j]^=s[i-1-j]^=s[j]^=s[i-1-j];
		puts(s);
	}
	else
		while (i)
		{
			i--;
			putchar(s[i]);
		}
}

struct polynomial
{
	coefficients val;
	int len;
	polynomial (int v)
	{
		memset(val,0,sizeof(coefficients));
		val[0]=v;
		len=1;
	}
	polynomial (int v[])
	{
		REPIFD(len,maxn-1,len>0&&v[len-1]==0)
			val[len]=0;
		val[len]=0;
		static int i;
		REP(i,0,len-1)
			val[i]=v[i];
	}
	polynomial ()
	{
		memset(val,0,sizeof(coefficients));
		len=0;
	}
	void init (int v)
	{
		memset(val,0,sizeof(coefficients));
		val[0]=v;
		len=1;
	}
	void init (int v[])
	{
		REPIFD(len,maxn-1,len>0&&v[len-1]==0)
			val[len]=0;
		val[len]=0;
		static int i;
		REP(i,0,len-1)
			val[i]=v[i];
	}
	void init ()
	{
		memset(val,0,sizeof(coefficients));
		len=0;
	}
	void reinit (int v=-1)
	{
		if (v>=0)
		{
			len=v;
			return;
		}
		REPIFD(len,maxn-1,len>0&&val[len-1]==0);
	}
	void reverse ()
	{
		static int i;
		REP(i,0,(len>>1)-1)
			val[i]^=val[len-1-i]^=val[i]^=val[len-1-i];
	}
	void reserve (int v=0)
	{
		len=v;
		static int i;
		REP(i,v,len-1)
			val[i]=0;
	}
	void output (int rev=0)
	{
		static int i;
		if (rev)
			REP(i,0,len-1)
				printf(i<len-1?"%d ":"%d\n",val[i]);
		else
			REPD(i,len-1,0)
				printf(i?"%d ":"%d\n",val[i]);
	}
	void output_len (int v,int rev=0)
	{
		static int i;
		if (rev)
			REP(i,0,v-1)
				printf(i<v-1?"%d ":"%d\n",val[i]);
		else
			REPD(i,v-1,0)
				printf(i?"%d ":"%d\n",val[i]);
	}
};

polynomial operator + (polynomial &x,polynomial &y);
polynomial operator - (polynomial &x,polynomial &y);
polynomial operator * (polynomial &x,polynomial &y);
polynomial operator ~ (polynomial &x);
polynomial operator ^ (polynomial &x,int y);
polynomial operator ! (polynomial &x);
polynomial operator / (polynomial &x,polynomial &y);
polynomial operator % (polynomial &x,polynomial &y);
bool operator == (polynomial &x,polynomial &y);
bool operator != (polynomial &x,polynomial &y);

namespace NTT
{
	int dft_len,dft_len_inv;
	coefficients V,X,Y;
	coefficients B,B0;
	void dft (int A[],int p)
	{
		static int i,j,k;
		static long long x,y;
		j=0;
		REP(i,0,dft_len-1)
		{
			if (i>j)
				A[i]^=A[j]^=A[i]^=A[j];
			REPIFR(k,dft_len>>1,(j^=k)<k);
		}
		REP(i,0,dft_len-1)
			V[i]=A[i];
		REPL(i,2,dft_len)
		{
			int gn=__usr_fpw(g,(mod-1)/i);
			REPS(j,0,dft_len-1,i)
			{
				int G=1;
				REP(k,j,j+(i>>1)-1)
				{
					x=V[k];
					y=(long long)V[k+(i>>1)]*G%mod;
					V[k]=(x+y)%mod;
					V[k+(i>>1)]=(x-y+mod)%mod;
					G=(long long)G*gn%mod;
				}
			}
		}
		if (p==-1)
		{
			REP(i,1,(dft_len>>1)-1)
				V[i]^=V[dft_len-i]^=V[i]^=V[dft_len-i];
			dft_len_inv=__usr_inv(dft_len);
			REP(i,0,dft_len-1)
				V[i]=(long long)V[i]*dft_len_inv%mod;
		}
		REP(i,0,dft_len-1)
			A[i]=V[i];
	}
	void inv (int A[],int len,int A0[]=X)
	{
		static int j,p,cur[30];
		p=0;
		while (len>1)
		{
			cur[p]=len;;
			p++;
			len=(len+1)>>1;
		}
		cur[p]=len;
		REPD(j,p,0)
		{
			if (cur[j]<=0)
				return;
			if (cur[j]==1)
			{
				memset(A0,0,sizeof(coefficients));
				A0[0]=__usr_inv(A[0]);
				if (j==0)
					memcpy(A,A0,sizeof(coefficients));
				continue;
			}
			dft_len=__usr_clz(cur[j]+1);
			dft_len_inv=__usr_inv(dft_len);
			static int i;
			REP(i,0,cur[j]-1)
				Y[i]=A[i];
			REP(i,cur[j],dft_len-1)
				Y[i]=0;
			dft(Y,1);
			dft(A0,1);
			REP(i,0,dft_len-1)
				A0[i]=(long long)A0[i]*(mod+2-(long long)Y[i]*A0[i]%mod)%mod;
			dft(A0,-1);
			REP(i,cur[j],dft_len-1)
				A0[i]=0;
			if (j==0)
				memcpy(A,A0,sizeof(coefficients));
		}
	}
	void root (int A[],int len,int A0[]=X)
	{
		static int j,p,cur[30];
		p=0;
		while (len>1)
		{
			cur[p]=len;
			p++;
			len=(len+1)>>1;
		}
		cur[p]=len;
		REPD(j,p,0)
		{
			if (cur[j]<=0)
				continue;
			if (cur[j]==1)
			{
				memset(A0,0,sizeof(coefficients));
				memset(B,0,sizeof(coefficients));
				A0[0]=1;
				B[0]=1;
				if (j==0)
					memcpy(A,A0,sizeof(coefficients));
				continue;
			}
			static int i;
			dft_len=__usr_clz(cur[j]+1);
			dft_len_inv=__usr_inv(dft_len);
			dft(B,1);
			REP(i,0,cur[j]-1)
				Y[i]=A[i];
			REP(i,cur[j],dft_len-1)
				Y[i]=0;
			dft(Y,1);
			dft(A0,1);
			REP(i,0,dft_len-1)
				B0[i]=(long long)B[i]*(mod+2-(long long)A0[i]*B[i]%mod)%mod;
			if (__builtin_popcount(cur[j])!=1)
			{
				dft(B0,-1);
				REP(i,cur[j],dft_len-1)
					B0[i]=0;
				dft(B0,1);
			}
			REP(i,0,dft_len-1)
				A0[i]=(inv2*A0[i]+inv2*Y[i]%mod*B0[i])%mod;
			dft(A0,-1);
			REP(i,cur[j],dft_len-1)
				A0[i]=0;
			REP(i,0,cur[j]-1)
				Y[i]=A0[i];
			REP(i,cur[j],dft_len-1)
				Y[i]=0;
			dft(Y,1);
			REP(i,0,dft_len-1)
				B[i]=(long long)B[i]*(mod+2-(long long)Y[i]*B[i]%mod)%mod;
			dft(B,-1);
			REP(i,cur[j],dft_len-1)
				B[i]=0;
			if (j==0)
				memcpy(A,A0,sizeof(coefficients));
		}
	}
}

polynomial operator + (polynomial &x,polynomial &y)
{
	static int i;
	int rep_len=max(x.len,y.len);
	static coefficients res;
	memset(res,0,sizeof(coefficients));
	REP(i,0,rep_len-1)
		res[i]=(x.val[i]+y.val[i])%mod;
	return polynomial(res);
}

polynomial operator - (polynomial &x,polynomial &y)
{
	static int i;
	int rep_len=max(x.len,y.len);
	static coefficients res;
	memset(res,0,sizeof(coefficients));
	REP(i,0,rep_len-1)
		res[i]=(mod+(x.val[i]-y.val[i])%mod)%mod;
	return polynomial(res);
}

polynomial operator * (polynomial &x,polynomial &y)
{
	static coefficients res,a,b;
	memset(res,0,sizeof(coefficients));
	memset(a,0,sizeof(coefficients));
	memset(b,0,sizeof(coefficients));
	NTT::dft_len=max(__usr_clz(x.len),__usr_clz(y.len));
	static int i;
	REP(i,0,x.len-1)
		a[i]=x.val[i];
	REP(i,0,y.len-1)
		b[i]=y.val[i];
	NTT::dft(a,1);
	NTT::dft(b,1);
	REP(i,0,NTT::dft_len-1)
		res[i]=(long long)a[i]*b[i]%mod;
	NTT::dft(res,-1);
	return polynomial(res);
}

polynomial operator ~ (polynomial &x)
{
	static polynomial res;
	res=x;
	NTT::inv(res.val,res.len);
	res.reinit();
	return res;
}

polynomial operator ^ (polynomial &x,int y)
{
	static polynomial res;
	res=x;
	NTT::inv(res.val,y);
	res.reinit();
	return res;
}

polynomial operator ! (polynomial &x)
{
	static polynomial res;
	res=x;
	NTT::root(res.val,res.len);
	res.reinit();
	return res;
}

polynomial operator / (polynomial &x,polynomial &y)
{
	static polynomial res;
	x.reverse();
	y.reverse();
	res=y^(x.len-y.len+1);
	res=x*res;
	res.reserve(x.len-y.len+1);
	res.reverse();
	x.reverse();
	y.reverse();
	return res;
}

polynomial operator % (polynomial &x,polynomial &y)
{
	static polynomial res;
	res=x/y;
	res=res*y;
	res=x-res;
	return res;
}

bool operator == (polynomial &x,polynomial &y)
{
	if (x.len!=y.len)
		return 0;
	static int i;
	REP(i,0,x.len-1)
		if (x.val[i]!=y.val[i])
			return 0;
	return 1;
}

bool operator != (polynomial &x,polynomial &y)
{
	return !(x==y);
}

int n,m;
int a[maxn];
polynomial p;

int main()
{
	read(n);
	read(m);
	int i,j;
	REP(i,1,n)
	{
		read(j);
		if (j<=m)
			a[j]=(a[j]+mod-4)%mod;
	}
	a[0]=1;
	p.init(a);
	p.reinit(m+1);
	p=!p;
	p.val[0]=(p.val[0]+1)%mod;
	p=~p;
	REP(i,1,m)
		write((p.val[i]*2)%mod,1);
	return 0;
}