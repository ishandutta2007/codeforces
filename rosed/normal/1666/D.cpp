#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 zmakioi
const int N=55;
char s[N],t[N];
int n,m;
int col[N];
int c[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		cin>>(s+1)>>(t+1);
		bool flag=0;
		n=strlen(s+1),m=strlen(t+1);
		for(int i=0;i<26;++i) col[i]=c[i]=0;
		for(int i=1;i<=m;++i)
		{
			++col[t[i]-'A'];
		}
		int pos=m;
		for(int i=n;i>=1;--i)
		{
			if(s[i]==t[pos]&&pos>0)
			{
				--col[t[pos]-'A'];
				--pos;
				for(int k=0;k<26;++k)
				{
					if(c[k]>0&&col[k]>0)
					{
						flag=1;
					}
					//c[k]=0;
				}
			}
			else ++c[s[i]-'A'];
		}
		if(flag||pos>0) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
/*
0 0
2 3
3 2

*/