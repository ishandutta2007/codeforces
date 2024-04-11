#include <cstdio>
using namespace std;
long long n,i,t,h,q,z,k,ans;
long long cube(long long i){return i*i*i;}
void search(int d,long long l,long long t)
{
	if (d==h+1)
	{
		if (t>ans)
			ans=t;
		return;
	}
	if (l<=0)
		return;
	long long i=1;
	while (cube(i+1)<=l) i++;
	search(d+1,l-cube(i),t+cube(i));
	search(d+1,cube(i)-1-cube(i-1),t+cube(i-1));
	return;
}
int main()
{
	scanf("%I64d",&n);
	i=1;
	while (t+cube(i)<=n)
	{
		h++;t+=cube(i);
		while (cube(i)+t>=cube(i+1)) i++;
		if (i>100000) break;
	}
	q=1;
	while (cube(q)<=n) q++;
	q--;
	search(1,n,0);
	printf("%I64d %I64d\n",h,ans);
	return 0;
}