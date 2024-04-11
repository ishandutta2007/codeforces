#include<algorithm>
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=1005;
int T,n,cnt[2],a[N];

int main()
{	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnt[0]=cnt[1]=0;
		rep(i,1,n) scanf("%d",&a[i]),++cnt[a[i]];
		if(cnt[0]>=cnt[1])
		{
			printf("%d\n",cnt[0]);
			rep(i,1,cnt[0]) printf("%d ",0);
			puts("");
		}
		else
		{
			if(cnt[1]&1) cnt[1]^=1;
			printf("%d\n",cnt[1]);
			rep(i,1,cnt[1]) printf("%d ",1);
			puts("");
		}
	}
	return 0;
}