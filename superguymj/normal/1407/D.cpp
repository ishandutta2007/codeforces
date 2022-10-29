#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=300005;
int n,h[N],stk1[N],stk2[N],top1,top2,f[N];

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&h[i]);
	stk1[top1=1]=stk2[top2=1]=1;
	rep(i,2,n)
	{
		int x=h[i],ans=n,jdg=0;
		while(top1 && h[stk1[top1]]<=x)
			ans=min(ans,f[stk1[top1]]+1),jdg=(h[stk1[top1]]==x),--top1;
		if(top1 && !jdg) ans=min(ans,f[stk1[top1]]+1); 
		jdg=0,stk1[++top1]=i;
		while(top2 && h[stk2[top2]]>=x)
			ans=min(ans,f[stk2[top2]]+1),jdg=(h[stk2[top2]]==x),--top2;
		if(top2 && !jdg) ans=min(ans,f[stk2[top2]]+1);
		stk2[++top2]=i;
		f[i]=ans;
	}
	printf("%d\n",f[n]);
	return 0;
}