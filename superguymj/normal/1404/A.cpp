#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=300005;
int T,n,k;
char s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		bool jdg=0;
		int tot0=0,tot=0;
		for(int i=1; i<=k; ++i)
		{
			bool x0=0,x1=0;
			for(int j=i; j<=n; j+=k)
				if(s[j]=='0') x0=1;
				else if(s[j]=='1') x1=1;
			if(x0 && x1) jdg=1;
			if(x0) ++tot0;
			else if(!x1) ++tot;
		}
		
		if(jdg) puts("NO");
		else if(tot0<=k/2 && tot0+tot>=k/2) puts("YES");
		else puts("NO");
	}
	return 0;
}