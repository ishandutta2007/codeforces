#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
const int mod=998244353;
int n,fac[1000001],inv[1000001],a,b,c,k,ans;
string s[100001];
int C(int x,int y)
{
	if(x<y||y<0)
		return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
	n=read();
	fac[0]=1;
	for(int i=1;i<=1000000;i++)
		fac[i]=(fac[i-1]*i)%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=1000000;i++)
		inv[i]=mod-(mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=1000000;i++)
		(inv[i]*=inv[i-1])%=mod;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		if(s[i]=="?W"||s[i]=="W?")
			a++;
		if(s[i]=="?B"||s[i]=="B?")
			b++;
		if(s[i]=="??")
			c++;
		if(s[i]=="BB")
			k++;
		if(s[i]=="WW")
			k--;
	}
	ans=C(a+b+c+c,k+b+c);
	int sum=1;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=="WW"||s[i]=="BB")
        {
            sum=0;
            break;
        }
        if(s[i]=="??")
            sum=2ll*sum%mod;
    }
    ans=(ans-sum+mod)%mod;
    sum=1;
    for(int i=1;i<=n;i++)
        if(s[i]=="WW"||s[i]=="BB"||s[i]=="W?"||s[i]=="?B"||s[i]=="WB")
        {
            sum=0;
            break;
        }
    ans=(ans+sum)%mod;
    sum=1;
    for(int i=1;i<=n;++i)
        if(s[i]=="WW"||s[i]=="BB"||s[i]=="?W"||s[i]=="B?"||s[i]=="BW")
        {
            sum=0;
            break;
        }
    ans=(ans+sum)%mod;
    cout<<(ans%mod+mod)%mod<<endl;
    return 0;
}