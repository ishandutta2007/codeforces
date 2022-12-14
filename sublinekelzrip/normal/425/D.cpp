#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num[2000010];
typedef pair<int,int> pii;
int last[1030010],maxn=0;
struct hsh
{
	int x,y,next;
}hs[100010];
pii a[1030010];
unsigned long long mul=233;
int get(int x,int y)
{
	unsigned long long p=x*mul+y;
	int k=p%1020407;
	for(int l=last[k];l;l=hs[l].next)
		if(hs[l].x==x&&hs[l].y==y)
			return 1;
	return 0;
}
int main()
{
	int n,n1,n2,n3,n4;
	scanf("%d",&n);
	for(n1=1;n1<=n;n1++)
	{
		scanf("%d%d",&a[n1].first,&a[n1].second);
		unsigned long long o=a[n1].first*mul+a[n1].second;
		int p=o%1020407;
		maxn++;
		hs[maxn].x=a[n1].first;
		hs[maxn].y=a[n1].second;
		hs[maxn].next=last[p];
		last[p]=maxn;
		num[a[n1].first+1000000]++;
	}
	sort(a+1,a+n+1);
	int sq=(int)sqrt(n+0.5),ans=0;
	for(n1=1;n1<=n;)
	{
		for(n2=n1;n2<=n&&a[n2].first==a[n1].first;n2++);
		n2--;
		if(num[a[n1].first+1000000]<=sq)
		{
			for(n3=n1;n3<=n2;n3++)
				for(n4=n3+1;n4<=n2;n4++)
				{
					int k=a[n4].second-a[n3].second;
					if(get(a[n3].first-k,a[n3].second)&&get(a[n4].first-k,a[n4].second))
						ans++;
				}
		}
		else
		{
			for(n3=1;n3<n1;n3++)
			{
				int k=a[n1].first-a[n3].first;
				if(get(a[n3].first,a[n3].second+k)&&get(a[n1].first,a[n3].second)&&get(a[n1].first,a[n3].second+k))
					ans++;
			}
		}
		n1=n2+1;
	}
	cout<<ans;	
}