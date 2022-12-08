//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
ll m,t,d,a[100111];
ll b[10000111];
int n;
int bf()
{
	ll cur=-d-1,ans=0;
	for(int i=1;i<=n+m-2;i++)
	{
		if(b[i]<=cur+d)continue;
		cur=b[i];ans++;
	}
	return ans;
}
int main()
{
	getii(m,n);
	getii(t,d);
	n+=2;
	a[1]=t;
	for(int i=2;i<n;i++)
	{
		geti(a[i]);
//		a[i]=rand()<<15|rand();
		b[i-1]=a[i];
	}
/*	for(int i=n-1;i<n-1+m;i++)b[i]=1ll*(i-(n-2))*t;
	sort(b+1,b+n+m-2);
	cerr<<bf()<<endl;*/
	
	a[n]=t*m;
	sort(a+1,a+n+1);
	ll cur=a[1],ans=1;
	ll per=d/t+1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=cur+d)continue;
		while(cur+d<a[i])
		{
			cur=cur+d+1;
			ll mn1=cur/t*t;
			if(mn1<cur)mn1+=t;
			if(mn1<=t*m&&mn1<=a[i])
			{
				cur=mn1;
				ans++;
				ll cid=cur/t;
				for(int j=30;j>=0;j--)
				{
					if(1.0*per*(1<<j)>m)continue;
					ll step=per*(1<<j);
					if(step+cid<=m&&1ll*(step+cid)*t<=a[i])
					{
						ans+=1<<j;
						cur+=step*t;
						cid+=per*(1<<j);
					}
				}
			}
			else
			{
				cur=a[i];
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}