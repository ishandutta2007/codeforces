#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
int n,l,r;
bool f;
int a[MAXN],b[MAXN],cnt[MAXN];
int main()
{
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	memset(cnt,0,sizeof(cnt));
	f=true;
	for(int i=1;i<=n;i++)
	{
		if(i<l||i>r)
		{
			if(a[i]!=b[i])
			{
				f=false;
				break;
			}
		}
		else
		{
			cnt[a[i]]++;
			cnt[b[i]]--;
		}
	}
	for(int i=1;i<=n;i++)
		if(cnt[i]!=0)
		{
			f=false;
			break;
		}
	if(!f) puts("LIE"); else puts("TRUTH");
	return 0;
}