#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10ll+ch-'0',ch=getchar();
	return x*f;
}
vector<int>ans;
void w(int x)
{
//	printf("x = %d\n",x);
	for(int i=1;i*i<=x;i++)
	if(x%i==0)
	{
		ans.emplace_back(i);
		if(i*i!=x)ans.emplace_back(x/i);
	}
}
int main()
{
	int T=read();
	while(T--)
	{
		ans.clear();
		int n=read(),m=read();
		w(__gcd(n-1,m-1));
		w(__gcd(n-2,m));
		w(__gcd(n,m-2));
		if((n&1)+(m&1)==1)ans.emplace_back(2);
		sort(ans.begin(),ans.end());
//		for(int x:ans)printf("%d ",x);puts("");
		int la=unique(ans.begin(),ans.end())-ans.begin();
		printf("%d ",la);
		for(int i=0;i<la;i++)printf("%d ",ans[i]);
		puts("");
	}
 	return 0;
}