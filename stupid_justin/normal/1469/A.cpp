#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int a[N],sum[N],b[N];
string s;
bool flag;
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>s;
		int l=0,t=0;
		flag=1;
		for (int i=0;i<s.size();i++)
		{
			if (s[i]=='(') l++;
			if (s[i]==')') l--;
			if (s[i]=='?') t++;
			if (l<0 && t==0) 
			{
				flag=0;
				break;
			}
			if (l<0) t--,l++;
			if (t>l)
			{
				l++,t--;
			}
		}
		if ((l+t)%2==1) flag=0;
		if (l>t) flag=0;
		if (flag) puts("YES");
		else puts("NO");
	}
}