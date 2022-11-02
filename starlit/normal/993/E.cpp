#include<bits/stdc++.h>
#define N 530000
using namespace std;
typedef double db;
const db pi=acos(-1);
struct cp
{db x,y;}a[N],b[N],W,w,p;
cp operator+(cp a,cp b)
{return{a.x+b.x,a.y+b.y};}
cp operator-(cp a,cp b)
{return{a.x-b.x,a.y-b.y};}
cp operator*(cp a,cp b)
{return{a.x*b.x-a.y*b.y,a.y*b.x+a.x*b.y};}
int n=1,m,i,j,k,x,sum,T[N],lst=-1;
__int64 ans;
inline void fft(cp*c,int t)
{
	for(i=0;i<n;i++)
	T[i]<i?swap(c[T[i]],c[i]),0:0;
	for(i=1;i<n;i<<=1)
	for(j=0,W={cos(pi/i),sin(pi/i)*t};j<n;j+=i<<1)
	for(k=0,w={1,0};k<i;k++,w=w*W)
	p=c[j+k+i]*w,c[j+k+i]=c[j+k]-p,c[j+k]=c[j+k]+p;
}
int main()
{
	scanf("%d%d",&m,&k);
	for(i=0;i<m;i++)
	{
		a[sum].x++,scanf("%d",&x);
		x=x<k;
		sum+=x,b[sum].x++;
		if(x)lst=i;
		ans+=i-lst;
	}
	printf("%I64d",ans);
	for(i=0;i<=sum>>1;i++)
	swap(a[i],a[sum-i]);
	for(;n<=sum<<1;n<<=1);
	for(i=1;i<n;i++)
	T[i]=T[i>>1]>>1|(i&1?n>>1:0);
	fft(a,1),fft(b,1);
	for(i=0;i<n;i++)a[i]=a[i]*b[i];
	fft(a,-1);
	for(i=1;i<=m;i++)
	printf(" %I64d",(__int64)((a[i+sum].x+0.5)/n));
}