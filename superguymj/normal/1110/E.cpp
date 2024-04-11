#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
int n;
int a[100005],b[100005];

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) a[i]=a[i]-a[i+1];
	sort(a+1,a+1+n);
	rep(i,1,n) scanf("%d",&b[i]);
	rep(i,1,n) b[i]=b[i]-b[i+1];
	sort(b+1,b+1+n);
	rep(i,1,n) if(a[i]!=b[i]) return puts("No"),0;
	puts("Yes");
	return 0;
}