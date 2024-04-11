#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l+r)>>1)
#define pb push_back

using namespace std;
typedef long long LL;
LL p1,p2,t1,t2,h,s,f[5005];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL getLL()
{
	char ch;
	while(!isdigit(ch=getchar()));
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	p1=getint(),t1=getLL();
	p2=getint(),t2=getLL();
	h=getint(),s=getint();
	LL INF=(h+p1+p2-s-1)/(p1+p2-s)*max(t1,t2);
	rep(i,1,h) f[i]=INF;
	rep(i,1,h)
	{
		rep(j,1,5000)
		{
			LL x=j*t1/t2;
			LL d=j*(p1-s)+(j*t1/t2)*(p2-s);
			if(x) d+=s;
			if(d>i) d=i;
			f[i]=min(f[i],f[i-d]+j*t1);
		}
		rep(j,1,5000)
		{
			LL x=j*t2/t1;
			LL d=j*(p2-s)+(j*t2/t1)*(p1-s);
			if(x) d+=s;
			if(d>i) d=i;
			f[i]=min(f[i],f[i-d]+j*t2);
		}
	}
	printf("%lld\n",f[h]); 
	return 0;
}