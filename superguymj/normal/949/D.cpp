#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=100005;
int n,d,b,a[N],c[N],L[N],R[N];

bool check(int Mid)
{
	int x=Mid+1,nw=0;
	rep(i,1,n) c[i]=a[i];
	rep(i,1,n)
	{
		if(x>n-Mid) return 1;
		while(nw+c[i]>=b && L[i]<=x && x<=R[i]) c[i]-=b-nw,++x,nw=0;
		if(L[i]<=x && x<=R[i]) nw+=c[i];
	}
	return x>n-Mid; 
}

int main()
{
	scanf("%d%d%d",&n,&d,&b);
	rep(i,1,n)
	{
		L[i]=(i-1)/(d+1)+1;
		R[i]=n-(n-i)/(d+1);
	}
	rep(i,1,n) scanf("%d",&a[i]);
	int l=0,r=n/2;
	while(l<=r)
		check(mid)?r=mid-1:l=mid+1;
	printf("%d\n",r+1);	
	return 0;
}