#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int abx(int x) {return max(-x,x);}
int main()
{
	scanf("%d",&n);
	int d=0;
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>1&&a[i]==a[i-1]) f=false;
		if(i>1&&abx(a[i]-a[i-1])!=1) 
		{
			if(d!=0&&d!=abx(a[i]-a[i-1])) f=false;
			d=abx(a[i]-a[i-1]);
		}
	}
	if(d==0) d=1;
	if(!f) {puts("NO"); return 0;}
	for(int i=1;i<=n;i++)
	{
		if(i>1)
		{
			int dx=(a[i-1]-1)/d,dy=a[i-1]-dx*d,nx=(a[i]-1)/d,ny=a[i]-nx*d;
			//printf("%d %d\n",dx,dy);
			if(abx(nx-dx)+abx(ny-dy)>1) {f=false; break;}
		}
	}
	if(!f) {puts("NO"); return 0;}
	puts("YES");
	printf("1000000000 %d\n",d);
	return 0;
}