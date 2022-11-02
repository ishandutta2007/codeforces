#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

map<int,int> f;
map<int,int>::iterator fc;
long long ans=0,ans0=0;
int k,luck,n,len,sum,e,a[200000],hash[200000];

int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d %d %d",&k,&luck,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	len=0;
	for (int i=1;i<=n;i++)
		if (a[i]==0) ++len; else
		{
			ans0+=(long long)len*(len+1)/2;
			len=0;
		}
	ans0+=(long long)len*(len+1)/2;
	sum=0;
	f.insert(pair<int,int>(0,1));
	for (int i=1;i<=n;i++)
	{
		sum=(sum+a[i])%(k-1);
		if (sum>=luck) e=sum-luck; else e=sum+(k-1)-luck;
		fc=f.find(e);
		if (fc!=f.end()) ans+=(long long)fc->second;
		fc=f.find(sum);
		if (fc==f.end()) f.insert(pair<int,int>(sum,1));
		else ++fc->second;
	}
	if (luck==0) cout<<ans0<<endl; else
	if (luck==k-1) cout<<ans-ans0<<endl; else
	cout<<ans<<endl;
	
	return 0;
}