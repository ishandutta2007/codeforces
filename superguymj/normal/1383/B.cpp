#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=1000005;
int a[N],n,ans,_;

int main() 
{
	scanf("%d",&_);
	while(_--) 
	{
		scanf("%d",&n),ans=0;
		rep(i,1,n) scanf("%d",&a[i]),ans^=a[i];
		if(!ans) {puts("DRAW"); continue;}
		repd(i,30,0) if(ans>>i&1)
		{
			int s=0;
			rep(j,1,n) if(a[j]>>i&1) s++;
			if((n-s)&1) puts("WIN");
			else 
			{
				if(s%4==3) puts("LOSE");
				else puts("WIN");
			}
			break;
		}
	}
	return 0;
}