#include <cstdio>
#include <algorithm>
using namespace std;
const int hash_mod=8636781;
struct state
{
	int p[17];
	inline void copy(state& x,int t)
	{
		for (int i=1;i<=t;i++)
			p[i]=x.p[i];
	}
};
unsigned long long hr[hash_mod];
double f[hash_mod];
int n,i,j,cnt,red;
int h[hash_mod],nx[hash_mod];
char op[10],ref[255];
state s,q;
bool cal[hash_mod];
inline unsigned long long hash(state& x,int t)
{
	unsigned long long ret=0;
	q.copy(x,t);
	sort(q.p+1,q.p+t);
	for (int i=t;i>=1;i--)
		ret=ret*193+q.p[i];
	return ret;
}
inline int insert(int t)
{
	unsigned long long hv=hash(s,t);
	int rv=hv%hash_mod;
	for (int q=h[rv];q;q=nx[q])
		if (hr[q]==hv)
			return q;
	cnt++;
	nx[cnt]=h[rv];
	hr[cnt]=hv;
	h[rv]=cnt;
	return cnt;
}
int dfs(int top,int dep)
{
	int id=insert(top);
	if (cal[id])
		return id;
	cal[id]=1;
	double r=1e18,g=1e18,b=1e18;
	int tid;
	int ut=top;
	int at[3]={s.p[ut]>>4,(s.p[ut]>>2)&3,s.p[ut]&3};
	if (at[0]>0&&at[1]>0&&at[2]>0)
	{
		ut++;
		at[0]=at[1]=at[2]=0;
	}
	int tcur=s.p[ut],lcur;
	int chk[4]={0,0,0,0};
	for (int i=top-1;i>=1;i--)
		if (((s.p[i]>>2)&3)>0&&
			(s.p[i]>>4)>0&&
			(s.p[i]&3)>0)
			chk[(s.p[i]>>2)&3]++;
	bool opt=chk[1]>0&&chk[2]>0&&chk[3]>0;
	for (int j=0;j<3;j++)
		if (at[j]==0)
			if (j==1||(j==2&&at[0]==0)||(j==0&&at[2]>0))
				for (int i=top-1;i>=1;i--)
				{
					int ac[3]={s.p[i]>>4,(s.p[i]>>2)&3,s.p[i]&3};
					if ((ac[0]>0)+(ac[1]>0)+(ac[2]>0)<=1)
						continue;
					lcur=s.p[i];
					for (int k=0;k<3;k++)
					{
						int t=ac[k];
						if (t==0)
							continue;
						if (n==6&&opt&&dep<red&&chk[t]>0&&k!=1)
							continue;
						if (n==6&&opt&&chk[t]>1&&k!=1)
							continue;
						if (k==2&&t==ac[0])
							continue;
						int tac[3]={ac[0],ac[1],ac[2]};
						tac[k]=0;
						if (tac[1]==0&&(tac[0]==0||tac[2]==0))
							continue;
						int tat[3]={at[0],at[1],at[2]};
						if (k==2)
							swap(tac[2],tac[0]);
						tat[j]=t;
						if (j!=1)
							if (tat[2]>tat[0]&&tat[0]!=0)
								swap(tat[2],tat[0]);
						s.p[ut]=(tat[0]<<4)|(tat[1]<<2)|tat[2];
						if (tac[1]==0||(tac[1]==1&&tac[0]==0&&tac[2]==0))
							tac[0]=tac[1]=tac[2]=0;
						s.p[i]=(tac[0]<<4)|(tac[1]<<2)|tac[2];
						tid=dfs(ut,dep+1);
						s.p[ut]=tcur;
						s.p[i]=lcur;
						if (t==1)
							if (f[tid]<r)
								r=f[tid];
						if (t==2)
							if (f[tid]<g)
								g=f[tid];
						if (t==3)
							if (f[tid]<b)
								b=f[tid];
					}
	}
	if (r==1e18&&g==1e18&&b==1e18)
	{
		f[id]=0;
		return id;
	}
	double ratio=1/6.0;
	if (r==1e18)
	{
		r=0;
		ratio+=1/6.0;
	}
	if (g==1e18)
	{
		g=0;
		ratio+=1/3.0;
	}
	if (b==1e18)
	{
		b=0;
		ratio+=1/3.0;
	}
	f[id]=(r/6.0+g/3.0+b/3.0+1)/(1-ratio);
	return id;
}
int main()
{
	scanf("%d",&n);
	ref['R']=1;
	ref['G']=2;
	ref['B']=3;
	for (i=1;i<=n;i++)
	{
		scanf("%s",op+1);
		if (op[1]>op[3])
			swap(op[1],op[3]);
		for (j=1;j<=3;j++)
		{
			if (op[j]=='R')
				red++;
			s.p[i]<<=2;
			s.p[i]|=ref[op[j]];
		}
	}
	red=red*3/n;
	i=dfs(n,0);
	printf("%.15lf\n",f[i]);
	return 0;
}