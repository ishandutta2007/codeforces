#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

long long int t,x,y,a,b,c,d,tmp;

int gcd(int x,int y)
{
	if (x%y==0) return y; else return (gcd(y,x%y));
}

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
		b=b-a;y=y-x;
		if (a==0){
			if (x==0) printf("0\n");
			else printf("-1\n");
		}
		else if (b==0){
			if (y==0) printf("0\n");
			else printf("-1\n");
		}
		else{
		    tmp=gcd(a,b);
		    a/=tmp;b/=tmp;
		    c=(x-1)/a+1;
		    d=(y-1)/b+1;
		    tmp=max(c,d);
		    printf("%I64d\n",(a+b)*tmp-x-y);
		}
	}
	return 0;
}