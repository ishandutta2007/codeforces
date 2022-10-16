#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,t,k;
int s;
int a[200010];
int ans[200010];
inline int check(int x)
{
	int res;
	if(a[x]!=-1){
		res=a[x];
		for(int i=1;i<=s;i++)if(ans[i]<=x)res++;
		return res;	
	}
	else
	{
		printf("? 1 %d\n",x);cout.flush();
		a[x]=res=read();
		for(int i=1;i<=s;i++)if(ans[i]<=x)a[x]--;
		return res;
	}	
}
int main()
{
	n=read(),t=read();
	for(int i=1;i<=2e5;i++)a[i]=-1;
	for(int ttt=1;ttt<=t;ttt++)
	{
		k=read();
		int le=1,ri=n,midd;
		while(le<=ri)
		{
			midd=(le+ri)/2;
			if(check(midd)<=midd-k)ri=midd-1;
			else le=midd+1;
		}
		ans[++s]=le;
		printf("! %d\n",le);fflush(stdout);
	}
}