#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;

const int N=1e5+5;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}

int n,k;
char s[N];
int a[N][27];
int b[N];
signed main()
{
	int T;cin>>T;
	while (T--)
	{
		bool flag=0;
		rd(n);rd(k);
		if (n%k) {puts("-1");continue;}
		scanf("%s",s+1);
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<26;j++) a[i][j]=a[i-1][j];
			a[i][s[i]-'a']++;
		}
		for (int i=n;i>=0;i--)
		{
			if (flag) break;
			// i 
			int tmp=0;
			for (int j=0;j<26;j++)  b[j]=(k-a[i][j]%k)%k,tmp+=b[j];
			if (i==n && tmp==0)
			{
				for (int i=1;i<=n;i++) cout<<s[i];puts("");flag=1;break;
			}
			if (tmp>n-i) continue;
			for (char c=s[i+1]+1;c<='z';c++)
			{
				if (flag) break;
				if (!b[c-'a']) b[c-'a']=k-1,tmp+=k-1;else b[c-'a']--,tmp--;
				if (tmp>n-i-1) {tmp-=k-1;b[c-'a']=0;continue;}
				while (tmp+i+1<n) b[0]+=k,tmp+=k;
				
				for (int j=1;j<=i;j++) cout<<s[j];cout<<c;
				for (char h='a';h<='z';h++) 
				{
					for (int j=1;j<=b[h-'a'];j++) putchar(h);
				}
				puts("");
				flag=1;
			}
		}
		if (!flag) puts("-1");
	}
}