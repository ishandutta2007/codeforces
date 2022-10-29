#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=400005;
int n;
char A[N],B[N];
int ans[N],ansn,L,R,rev;

int main()
{	
	int _;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d",&n);
		scanf("%s",A+1);
		scanf("%s",B+1);
		ansn=0;
		L=1,R=n,rev=0;
		repd(i,n,1)
		{
			if(rev==0)
			{
				if(A[R]==B[i]) --R;
				else
				{
					if(A[L]!=B[i])
					{
						ans[++ansn]=i;
						++L,rev^=1;
					}
					else
					{
						ans[++ansn]=1;
						ans[++ansn]=i;
						++L,rev^=1;
					}
				}
			}
			else
			{
				if((A[L]^1)==B[i]) ++L;
				else
				{
					if(A[R]==B[i])
					{
						ans[++ansn]=i;
						--R,rev^=1;
					}
					else
					{
						ans[++ansn]=1;
						ans[++ansn]=i;
						--R,rev^=1;
					}
				}
			}
		}
		printf("%d",ansn);
		rep(i,1,ansn) printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}