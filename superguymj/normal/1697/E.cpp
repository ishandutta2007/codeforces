#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l+r)>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define pb push_back

using namespace std;
const int N=105,mod=998244353;
typedef long long LL;
int n,s1,s2,s3,s4;
LL c[N][N],flv[N],ans;
struct point{int x,y;} p[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int dis(point a,point b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}

bool check(int i,int j,int k)
{	
	int x=dis(p[i],p[j]);
	if(x>=dis(p[i],p[k]) || x>=dis(p[j],p[k])) return 0;
	return 1;
}

int main()
{
	n=getint();
	rep(i,1,n) p[i].x=getint(),p[i].y=getint();
	rep(i,1,n) rep(j,i+1,n)
	{
		bool jdg=1;
		rep(k,1,n) if(i!=k && j!=k)
		{
			if(!check(i,j,k)) {jdg=0; break;}
		}
		s2+=jdg;
	}
	rep(i,1,n) rep(j,i+1,n) rep(k,j+1,n)
	{
		int x=dis(p[i],p[j]);
		int y=dis(p[j],p[k]);
		int z=dis(p[k],p[i]);
		if(x!=y || x!=z || y!=z) continue;
		bool jdg=1;
		rep(l,1,n) if(i!=l && j!=l && k!=l)
		{
			if(!check(i,j,l)) {jdg=0; break;}
			if(!check(i,k,l)) {jdg=0; break;}
			if(!check(j,k,l)) {jdg=0; break;}
		}
		s3+=jdg;
	}
	rep(i,1,n) rep(j,i+1,n) rep(k,j+1,n) rep(l,k+1,n)
	{
		int x=dis(p[i],p[j]);
		int y=dis(p[j],p[k]);
		int z=dis(p[k],p[i]);
		int _x=dis(p[i],p[l]);
		int _y=dis(p[j],p[l]);
		int _z=dis(p[k],p[l]);
		if(!(x==y && y==z && z==_x && _x==_y && _y==_z)) continue;
		bool jdg=1;
		rep(o,1,n) if(i!=o && j!=o && k!=o && l!=o)
		{
			if(!check(i,j,o) || !check(i,l,o)) {jdg=0; break;}
			if(!check(i,k,o) || !check(j,l,o)) {jdg=0; break;}
			if(!check(j,k,o) || !check(k,l,o)) {jdg=0; break;}
		}
		s4+=jdg;
	}
	s1=n-2*s2-3*s3-4*s4;
	rep(i,0,n) c[i][0]=1;
	rep(i,1,n) rep(j,1,i) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	flv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod;
	rep(i,0,s2) rep(j,0,s3) rep(k,0,s4)
	{
		int x=s1+i+2*(s2-i)+j+3*(s3-j)+k+4*(s4-k);
		ans=(ans+c[s2][i]*c[s3][j]%mod*c[s4][k]%mod*c[n][x]%mod*flv[x])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}