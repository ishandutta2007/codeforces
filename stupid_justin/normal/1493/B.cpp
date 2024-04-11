#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;

const int N=3e5+5;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}

int h,m;
string s;
int rev[10];
bool chk(int H,int M)
{
	if (rev[H/10]==-1) return 0;
	if (rev[H%10]==-1) return 0;
	if (rev[M/10]==-1) return 0;
	if (rev[M%10]==-1) return 0;
	if (rev[H/10]+rev[H%10]*10>=m) return 0;
	if (rev[M/10]+rev[M%10]*10>=h) return 0;
	return 1;
}
int H,M;
signed main()
{
	rev[0]=0;
	rev[1]=1;
	rev[2]=5;
	rev[3]=-1;
	rev[4]=-1;
	rev[5]=2;
	rev[6]=-1;
	rev[7]=-1;
	rev[8]=8;
	rev[9]=-1;
	
	int T;cin>>T;
	while (T--)
	{
		rd(h);rd(m);cin>>s;
		H=(s[0]-'0')*10+s[1]-'0';
		M=(s[3]-'0')*10+s[4]-'0';
		while (!chk(H,M))
		{
			M++;if(M==m) H++,M%=m;
			if (H==h) H=0;
		}
		if (H<10) cout<<"0";cout<<H<<":";
		if (M<10) cout<<"0";cout<<M<<endl;
	}
}