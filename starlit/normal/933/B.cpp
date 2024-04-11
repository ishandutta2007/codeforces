#include<bits/stdc++.h>
#define N 233333
using namespace std;
long long p,a[N],tp;
int k,i;
int main()
{
	scanf("%lld%d",&p,&k);
	for(i=0;;i++)
	{
        a[i]=(p%k+k)%k;
        if(p>=0&&p<k)break;
        p=(a[i]-p)/k;
	}
	if(a[i]==0&&i)i--;
	i++;printf("%d\n",i);
	for(int j=0;j<i;j++)
    printf("%d ",a[j]);
}