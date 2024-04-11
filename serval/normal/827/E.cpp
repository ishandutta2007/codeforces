#include <cstdio>
#include <cmath>
using namespace std;
const int N=1100005;
const double pi=acos(-1);
struct complex
{
	double r,i;
	complex(){}
	complex(double real,double image)
	{
		r=real;
		i=image;
	}
};
complex operator + (complex &a,complex &b)
{
	return complex(a.r+b.r,a.i+b.i);
}
complex operator - (complex &a,complex &b)
{
	return complex(a.r-b.r,a.i-b.i);
}
complex operator * (complex &a,complex &b)
{
	return complex(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
}
complex f[N],g[N];
int t;
int n,i,j,k,ans;
int dft_len;
char s[N];
int rev[N];
complex V[N];
bool chk[N];
void dft(complex A[],double p)
{
	complex x,y;
	for (i=0;i<dft_len;i++)
		V[rev[i]]=A[i];
	for (i=2;i<=dft_len;i<<=1)
	{
		complex wn=complex(cos(2*p*pi/i),sin(2*p*pi/i));
		for (j=0;j<dft_len;j+=i)
		{
			complex w=complex(1,0);
			for (k=0;k<(i>>1);k++)
			{
				x=V[j+k];
				y=V[j+k+(i>>1)]*w;
				V[j+k]=x+y;
				V[j+k+(i>>1)]=x-y;
				w=w*wn;
			}
		}
	}
	if (p<0)
		for (i=0;i<dft_len;i++)
			V[i].r/=dft_len;
	for (i=0;i<dft_len;i++)
		A[i]=V[i];
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		for (dft_len=1;dft_len<=n;dft_len<<=1);
		dft_len<<=1;
		for (i=0;i<dft_len;i++)
		{
			rev[i]=0;
			for (j=1,k=i;j<dft_len;j<<=1,k>>=1)
			{
				rev[i]<<=1;
				rev[i]|=k&1;
			}
		}
		for (i=0;i<=n;i++)
		{
			f[i].r=(s[i]=='V')?1:0;
			g[i].r=(s[n-i]=='K')?1:0;
			f[i].i=g[i].i=0;
		}
		for (i=n+1;i<dft_len;i++)
			f[i].r=g[i].r=f[i].i=g[i].i=0;
		dft(f,1);
		dft(g,1);
		for (i=0;i<dft_len;i++)
			f[i]=f[i]*g[i];
		dft(f,-1);
		for (i=1;i<=n;i++)
			chk[i]=f[n-i].r<0.5&&f[n+i].r<0.5;
		ans=0;
		for (i=1;i<=n;i++)
		{
			for (j=i<<1;j<=n;j+=i)
				chk[i]&=chk[j];
			ans+=chk[i];
		}
		printf("%d\n",ans);
		for (i=1;i<=n;i++)
		{
			ans-=chk[i];
			if (chk[i])
				printf(ans?"%d ":"%d\n",i);
		}
	}
	return 0;
}