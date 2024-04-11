#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=50005,M=230;
int n,mod,m,L[M],R[M],id[N],lim,s[N],tot;
LL K,T[2][2],mxt[2][2],mxt1[2][2],f[2],f1[2];
LL c[M][M][2][2],P[2][2];
map <LL,int> mp;
struct data
{
	LL x; int y;

	bool operator < (const data &t) const
	{
		return x<t.x;
	}
} dat[N];
struct num
{
	LL a,b;

	num operator * (num t)
	{
		num rt;
		rt.a=b,rt.b=(a*t.a+b*t.b)%mod;
		return rt;
	}

	num operator * (LL t)
	{
		num rt;
		rt.a=a*t%mod,rt.b=b*t%mod;
		return rt;
	}

	num operator + (num t)
	{
		num rt;
		rt.a=(a+t.a)%mod,rt.b=(b+t.b)%mod;
		return rt;
	}
} ans,tmp;

LL get(LL x)
{
	LL rt=mp[x];
	return rt?rt:s[x%n];
}

void trf(LL T[][2])
{
	LL x=T[1][0],y=T[1][1];
	T[1][0]=(T[0][0]*tmp.a+T[1][0]*tmp.b)%mod;
	T[1][1]=(T[0][1]*tmp.a+T[1][1]*tmp.b)%mod;
	T[0][0]=x,T[0][1]=y;
}

void prepare()
{
	T[0][0]=T[1][1]=1;
	rep(i,2,n+1)
	{
		tmp=(num){s[(i-2)%n],s[(i-1)%n]};
		trf(T);
	}
	lim=max(2,(int)sqrt(n));
	rep(i,0,n-1) id[i]=i/lim;
	rep(i,0,n-1) R[id[i]]=i;
	repd(i,n-1,0) L[id[i]]=i;
	
	rep(i,0,id[n-1])
	{
		memset(P,0,sizeof(P));
		P[0][0]=P[1][1]=1;
		rep(j,L[i]+2,n)
		{
			tmp=(num){s[j-2],s[j-1]};
			trf(P);
			if(j==n || L[id[j]]==j-1)
				rep(_x,0,1)
					rep(_y,0,1)
						c[i][id[j-2]][_x][_y]=P[_x][_y];
		}
	}
}

num trf(num x,int l,int r)
{
	return (num){(c[l][r][0][0]*x.a+c[l][r][0][1]*x.b)%mod,(c[l][r][1][0]*x.a+c[l][r][1][1]*x.b)%mod};
}

num query_s(int l,int r,num nw)
{
	if(id[l]+1>=id[r])
	{
		rep(i,l+2,r+1)
			nw=nw*(num){s[i-2],s[i-1]};
		return nw;
	}
	rep(i,l+2,R[id[l]]+2)
		nw=nw*(num){s[i-2],s[i-1]};
	nw=trf(nw,id[l]+1,id[r]-1);
	rep(i,L[id[r]]+2,r+1)
		nw=nw*(num){s[i-2],s[i-1]};
	return nw;
}

num query_b(num nw,LL x)
{
	f[0]=nw.a,f[1]=nw.b;
	memcpy(mxt,T,sizeof(T));
	while(x)
	{
		if(x&1)
		{
			memset(f1,0,sizeof(f1));
			rep(i,0,1) rep(j,0,1) f1[i]=(f1[i]+f[j]*mxt[i][j])%mod;
			rep(i,0,1) f[i]=f1[i];
		}
		memset(mxt1,0,sizeof(mxt1));
		rep(i,0,1) rep(j,0,1) rep(k,0,1) mxt1[i][j]=(mxt1[i][j]+mxt[i][k]*mxt[k][j])%mod;
		rep(i,0,1) rep(j,0,1) mxt[i][j]=mxt1[i][j];
		x>>=1;
	}
	nw.a=f[0],nw.b=f[1];
	return nw;
}

num query(LL l,LL r,num nw)
{
	if(l/n==r/n) return query_s(l%n,r%n,nw);
	nw=query_s(l%n,n-1,nw)*(num){s[n-1],s[0]};
	LL len=(r/n)-(l/n+1);
	nw=query_b(nw,len);
	nw=query_s(0,r%n,nw);
	return nw;
}

int main()
{
	scanf("%lld%d%d",&K,&mod,&n);
	rep(i,0,n-1) scanf("%d",&s[i]);
	scanf("%d",&m);
	rep(i,1,m)
	{
		LL x; int y;
		scanf("%lld%d",&x,&y);
		if(x<K) dat[++tot]=(data){x,y},mp[x]=y;
	}

	prepare();
	ans=(num){0,1};
	sort(dat+1,dat+1+tot);

	if(tot)
	{	
		ans=query(0,dat[1].x-1,ans);
		tmp=(num){get(dat[1].x-1),get(dat[1].x)};
		ans=ans*tmp;
		tmp=(num){get(dat[1].x),get(dat[1].x+1)};
		ans=ans*tmp;
	}

	rep(i,2,tot)
	{
		if(dat[i-1].x+1==dat[i].x)
		{
			tmp=(num){get(dat[i].x),get(dat[i].x+1)};
			ans=ans*tmp;
		}
		else
		{
			ans=query(dat[i-1].x+1,dat[i].x-1,ans);
			tmp=(num){get(dat[i].x-1),get(dat[i].x)};
			ans=ans*tmp;
			tmp=(num){get(dat[i].x),get(dat[i].x+1)};
			ans=ans*tmp;	
		}
	}
	if(tot) ans=query(dat[tot].x+1,K,ans);
	else ans=query(0,K,ans);
	printf("%lld\n",(ans.a+mod)%mod);
	return 0;
}