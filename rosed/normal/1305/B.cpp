#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=1010;
	int haku;
	int n;
	char s[N]; 
	int sum;
	int a[N][N];
	inline void main()
	{
		scanf("%s",s+1);n=strlen(s+1);
		while("1")
		{
			++sum;
			int l=1,r=n;bool flag=0;
			while(l<=r)
			{
				while(l<=n&&s[l]!='(') ++l;
				while(r>=1&&s[r]!=')') --r;
				if(l>n||r<1||r<=l) break;
				a[sum][++a[sum][0]]=l;
				a[sum][++a[sum][0]]=r;
				s[l]=s[r]=0;
			}
			if(!flag) break;
		}
		if(!a[sum][0]) --sum;
		printf("%lld\n",sum);
		for(int i=1;i<=sum;++i)
		{
			printf("%lld\n",a[i][0]);
			sort(a[i]+1,a[i]+a[i][0]+1);
			for(int j=1;j<=a[i][0];++j) printf("%lld ",a[i][j]);
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*

*/