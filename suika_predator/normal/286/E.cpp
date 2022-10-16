#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
struct c
{
	double r,i;
	c(){r=i=0.0;}
	c(const double x,const double y){r=x,i=y;}
	c operator+(const c &x)const{return c(r+x.r,i+x.i);}
	c operator+=(const c &x){return *this=*this+x;}
	c operator-(const c &x)const{return c(r-x.r,i-x.i);}
	c operator-=(const c &x){return *this=*this-x;}
	c operator*(const c &x)const{return c(r*x.r-i*x.i,r*x.i+i*x.r);}
	c operator*=(const c &x){return *this=*this*x;}
}A[2333333],x[2333333];
const double pi=3.1415926535897932384626433832795;
int l=1,r[2333333];
inline void fft(c *a,int ty)
{
	for(int i=0;i<l;i++)x[r[i]]=a[i];
	for(int i=0;i<l;i++)a[i]=x[i];
	for(int i=1;i<l;i<<=1)
	{
		c w(cos(pi/i),ty*sin(pi/i));
		for(int j=0;j<l;j+=i<<1)
		{
			c wn(1.0,0.0);
			for(int k=j;k<i+j;k++)
			{
				c t=wn*a[i+k];
				a[i+k]=a[k]-t;
				a[k]+=t;
				wn*=w;
			}
		}
	}
}
int n,m,w;
int v[2333333];
vector<int> ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&w),A[w].r=v[w]=1;
//	for(int i=1;i<=m;i++)cout<<A[i].r<<' ';cout<<endl;
	while(l<=m*2)l<<=1;
	for(int i=1;i<l;i<<=1)
		for(int j=0;j<i;j++)
			r[i+j]=r[j]+l/(i*2);
	fft(A,1);
	for(int i=0;i<l;i++)A[i]*=A[i];
	fft(A,-1);
//	for(int i=0;i<=m;i++)cout<<(int)(A[i].r/l+0.5)<<' ';cout<<endl;
	for(int i=0;i<=m;i++)
	{
		if(v[i]==0&&(int)(A[i].r/l+0.5))
		{
			printf("NO\n");
			return 0;
		}
		else if(v[i]==1&&(int)(A[i].r/l+0.5)==0)
		{
			ans.push_back(i);
		}
	}
	printf("YES\n%d\n",ans.size());
	for(auto o:ans)printf("%d ",o);
	return 0;
}