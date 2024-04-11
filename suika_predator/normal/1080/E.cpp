#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#define ll long long
using namespace std;
const long long mask=0x3fffffffffffffffll;
long long a[555],t[255];
int far[555],lim,pos,maxx;
int n,m;
int gao(int l)
{
//	cerr<<"gao "<<endl;
	memset(a,0,sizeof(a));
	memset(far,0,sizeof(far));
	lim=pos=maxx=0;
	a[0]=-1e9;
	for(int i=0;i<l;i++)
	{
		a[2*i+1]=t[i],a[2*i+2]=-1e9;
	}
	l=l*2+1;
	for(int i=0;i<l;i++)
	{
		if(lim<i)
		{
			far[i]=0;
			while(i+far[i]+1<l&&i-far[i]-1>=0&&a[i+far[i]+1]==a[i-far[i]-1])far[i]++;
			if(lim<i+far[i])lim=i+far[i],pos=i;
		}
		else
		{
			far[i]=far[pos*2-i];
			if(i+far[i]>=lim)
			{
				far[i]=lim-i;
				while(i+far[i]+1<l&&i-far[i]-1>=0&&a[i+far[i]+1]==a[i-far[i]-1])far[i]++;
				if(lim<i+far[i])lim=i+far[i],pos=i;
			}
		}
		if(maxx<far[i])maxx=far[i];
	}
	int ret=0;
	for(int i=0;i<l;i++)
	{
	//	cerr<<far[i]<<' ';
		ret+=(far[i]+1)/2;
	}
//	cerr<<endl;
	return ret;
}
char s[255][255];
long long hs[255][255][255];
int cnt[255];
long long tb[255];
inline long long ran()
{
	ll x = rand() * 32768 + rand();
	ll y = rand() * 32768 + rand();
	ll ans = x * 1073741824 + y;
/*	static unsigned long long x=time(0)^(unsigned long long)(new char);
	x^=x<<13;
	x^=x>>37;
	x^=x<<25;
*/
	return ans&mask;
}
int main()
{
	srand(time(0));
	long long ans=0;
	cin>>n>>m;
//	cerr<<mask<<endl;
	for(char c='a';c<='z';c++)tb[c]=ran();//,cerr<<tb[c]<<' ';cerr<<endl;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
	}
	int mcnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
		{
			int ex=0;
			long long cur=0;
			memset(cnt,0,sizeof(cnt));
			for(int r=l;r<=m;r++)
			{
				cnt[s[i][r]]++;
				if(cnt[s[i][r]]%2)ex++;
				else ex--;
				cur+=tb[s[i][r]];cur&=mask;
				if(ex<=1)hs[i][l][r]=cur;
				else hs[i][l][r]=-(++mcnt);
//				cerr<<i<<' '<<l<<' '<<r<<' '<<s[i][r]<<' '<<ex<<' '<<cur<<' '<<hs[i][l][r]<<endl;
			}
		}
	}
	for(int l=1;l<=m;l++)
	{
		for(int r=l;r<=m;r++)
		{
			int last=0;
			hs[n+1][l][r]=-1;
			for(int i=1;i<=n+1;i++)
			{
				if(hs[i][l][r]<0)
				{
					ans+=gao(i-last-1);
					last=i;
				}
				else t[i-last-1]=hs[i][l][r];
//				cerr<<t[i-1]<<' ';
			}
//			cerr<<w<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}