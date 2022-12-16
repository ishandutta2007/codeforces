#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-6)
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
	char s[N];
	int n,t;
	int son[N][5];
	int num[N];
	bool b[150];
	bool con;
	char ans[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			scanf("%s",s+1);
			n=strlen(s+1);
			con=0;
			t=0;
			memset(son,0,sizeof(son));
			memset(num,0,sizeof(num));
			memset(b,0,sizeof(b));
			if(n==1)
			{
				puts("YES");
				cout<<s[1];
				for(int i=0;i<26;++i) if(i+'a'!=s[1]) cout<<(char)(i+'a');
				puts("");
				continue; 
			}
			for(int i=1;i<n;++i)
			{
				if(son[s[i]][1]==s[i+1]||son[s[i]][2]==s[i+1]) continue;
				if(num[s[i]]==2||num[s[i+1]]==2)
				{
					puts("NO");
					con=1;
					break;
				}
				son[s[i]][++num[s[i]]]=s[i+1];
				son[s[i+1]][++num[s[i+1]]]=s[i];
			}
			if(con) continue;
			int st=0;
			for(int i=1;i<=n;++i)
			{
				if(num[s[i]]==1&&!st) st=s[i];
				b[s[i]]=1;
			}
			if(!st)
			{
				puts("NO");
				continue;
			}
			puts("YES");
			ans[++t]=st;
			int now=son[st][1];
			while("haku")
			{
				ans[++t]=now;
				if(num[now]==1) break;
				if(son[now][1]==st)
				{
					st=now,now=son[now][2];
				}
				else
				{
					st=now,now=son[now][1];
				}
			}
			for(int i=0;i<26;++i) if(!b[i+'a']) ans[++t]=i+'a';
			for(int i=1;i<=t;++i) cout<<ans[i];
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}