#include<bits/stdc++.h>
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define rd(x) x=read()
using namespace std;
const int N=(1<<20)+5;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int n,m,k;
string s;
string ans;
bool can[N];
vector<int> del;
int cnt,B,E;
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		del.clear();
		cin>>n>>k;cin>>s;s=" "+s;cnt=0;
        for (int i=1;i<max(1LL,1+k-20);i++) if (s[i]=='0') cnt++;
        B=1,E=max(1LL,1+k-20)-1;
		for (int i=1;i<=n-k+1;i++)
		{
			int tmp=0;
			for (int j=max(i,i+k-20);j<=i+k-1;j++)
			{
				tmp=tmp*2+('1'-s[j]);
			}
			//cout<<tmp<<endl;
			if (cnt==0) can[tmp]=1;
			del.push_back(tmp);
            if (s[B]=='0') cnt--;B++;
            E++;if (s[E]=='0') cnt++;
		}
		for (int i=0;i<=n-k+1;i++)
		{
			if (can[i]==0) 
			{
				ans="";
				int x=i;
				while (x)
				{
					char tmp='0'+(x&1);
					ans=tmp+ans;
					x>>=1;	
				} 
				if (ans.size()>k) puts("NO");
				else 
				{
					puts("YES");
					for (int i=ans.size()+1;i<=k;i++) putchar('0');
					cout<<ans<<"\n";
				}
				break;
			}
		}
		for (int i=0;i<del.size();i++) can[del[i]]=0;
	}
}