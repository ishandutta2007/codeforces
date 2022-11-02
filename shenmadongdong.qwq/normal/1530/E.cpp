#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const unsigned _mod=998244353;
const unsigned mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(int &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y>0){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n;
char s[100010],h[100010];
int b[27];
int main()
{
	DC
	{
		M(b,0);
		int cnt=0,num=0,mn=inf,qwq=-1;
		cin>>s+1;
		n=strlen(s+1);
		F(i) if (s[i]<mn) mn=s[i];
		F(i) if (s[i]==mn) cnt++;
		F(i) b[s[i]-'a']++;
		rep(i,0,25) if (qwq==-1&&b[i]==1) qwq=i;
		rep(i,0,25) if (b[i]) num++;
		if (num==1) cout<<s+1;
		else if (qwq!=-1)
		{
			putchar(qwq+'a');
			b[qwq]--;
			int pos=0;
			while(pos<=25)
			{
				while(b[pos]) putchar(pos+'a'),b[pos]--;
				pos++;
			}
		}
		else if (cnt<=n-cnt+2)
		{
			b[mn-'a']--;
			rep(i,1,n+5) h[i]=0;
			h[1]=mn;
			rep(i,1,n/2)
			{
				if (!b[mn-'a']) break;
				h[i*2]=mn,b[mn-'a']--;
			}
			b[mn-'a']=0;
			int pos=0,wz=1;
			while(pos<=25)
			{
				while(b[pos]) 
				{
					while(h[wz]) wz++;
					h[wz]=pos+'a',b[pos]--;
				}
				pos++;
			}
			if (wz>n) return 1;
			F(i) putchar(h[i]); 
		}
		else if (num==2)
		{
			putchar(mn);
			b[mn-'a']--;
			rep(i,0,25) if (b[i]&&i+'a'!=mn) while(b[i]) putchar(i+'a'),b[i]--;
			while(b[mn-'a']) putchar(mn),b[mn-'a']--;
		}
		else if (num>=3)
		{
			putchar(mn);
			b[mn-'a']--;
			int mn2=inf;
			F(i) if (s[i]>mn&&s[i]<mn2) mn2=s[i];
			putchar(mn2);
			while(b[mn-'a']) putchar(mn),b[mn-'a']--;
			b[mn-'a']=0;
			b[mn2-'a']--;
			int mn3=inf;
			F(i) if (s[i]>mn2&&s[i]<mn3) mn3=s[i];
			putchar(mn3);
			b[mn3-'a']--;
			int pos=0;
			while(pos<=25)
			{
				while(b[pos]) putchar(pos+'a'),b[pos]--;
				pos++;
			}
		}
		else return 1;
		putchar(10);
	}
	return 0;
}