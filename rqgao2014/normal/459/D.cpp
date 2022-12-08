#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
map<int,int>m;
int a[1000005],res[1000005],c[1000005];

void add(int x,int y){
	for(;x<=1000000;x+=x&(-x))
		c[x]+=y;
}
int get(int x){
	int y=0;
	for(;x>0;x-=x&(-x))
		y+=c[x];
	return y;
}
int main()
{
	int n;long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		res[i]=++m[a[i]];
	}
	for(int i=1;i<=n;i++)
	{
		int j=m[a[i]]-res[i]+1;
		ans+=i-1-get(j);
		add(res[i],1);
	}
	printf("%I64d\n",ans);
}