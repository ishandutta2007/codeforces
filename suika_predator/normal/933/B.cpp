#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
long long p;
int k;
long long a[233];
int main()
{
	scanf("%lld%d",&p,&k);
	a[0]=p;
	int cur=0;
	while(a[cur]>=k||a[cur]<0)
	{
		long long q=a[cur]/k,c=a[cur]%k;
		if(c<0)q--,c+=k;
		a[cur+1]=-q;a[cur]=c;
		//cout<<cur<<' '<<q<<' '<<c<<endl;
		cur++;
	}
	if(a[cur]<0)return printf("-1\n"),0;
	printf("%d\n",cur+1);
	for(int i=0;i<=cur;i++)printf("%lld ",a[i]);
	return 0;
}