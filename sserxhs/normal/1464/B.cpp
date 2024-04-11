#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+2;
ll ans,cur;
int s[N],ps[3][N],ns[3][N],pss[2][N],nss[2][N];
int n,c,i,t,m,j,k,x,y;
inline void read(register int &x)
{
	register int c=getchar(),fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
int main()
{
	c=getchar();
	while (c==48||c==49||c=='?')
	{
		s[++n]=c=='?'?2:c^48;
		c=getchar();
	}
	read(x);read(y);
	for (i=1;i<=n;i++) ps[0][i]=ps[0][i-1]+(s[i]==0);
	for (i=1;i<=n;i++) ps[1][i]=ps[1][i-1]+(s[i]==1);
	for (i=1;i<=n;i++) ps[2][i]=ps[2][i-1]+(s[i]==2);
	for (i=n;i;i--) ns[0][i]=ns[0][i+1]+(s[i]==0);
	for (i=n;i;i--) ns[1][i]=ns[1][i+1]+(s[i]==1);
	for (i=n;i;i--) ns[2][i]=ns[2][i+1]+(s[i]==2);
	for (i=1;i<=n;i++) if (s[i]==2||s[i]==0)
		cur+=(ll)ps[1][i]*y;
	else cur+=(ll)(ps[0][i]+ps[2][i])*x;
	//for (i=1;i<=n;i++) printf("%d ",s[i]);puts("");
	//printf("%lld\n",cur);
	ans=cur;
	for (i=1;i<=n;i++) if (s[i]==2)//1
	{
		cur-=(ll)(ps[1][i]+ps[2][i-1])*y+(ll)ns[1][i]*x;
		cur+=(ll)ps[0][i]*x+(ll)(ns[0][i]+ns[2][i+1])*y;
	//printf("%lld\n",cur);
		if (ans>cur) ans=cur,j=i;
	}//puts("");
	//printf("%lld\n",cur);
	for (i=1;i<=n;i++) if (s[i]==2)//0
	{
		cur-=(ll)(ps[0][i]+ps[2][i-1])*x+(ll)ns[0][i]*y;
		cur+=(ll)ps[1][i]*y+(ll)(ns[1][i]+ns[2][i+1])*x;
	//printf("%lld\n",cur);
		if (ans>cur) ans=cur,k=i;
		//ans=min(ans,cur);
	}/*if (ans<0) while (1);
	if (k)
	{
		for (i=1;i<=n;i++) pss[0][i]=pss[0][i-1]+(s[i]==0||s[i]==2&&i<=k);
		for (i=1;i<=n;i++) pss[1][i]=pss[1][i-1]+(s[i]==1||s[i]==2&&i>k);
		for (i=n;i;i--) nss[0][i]=nss[0][i+1]+(s[i]==0||s[i]==2&&i<=k);
		for (i=n;i;i--) nss[1][i]=nss[1][i+1]+(s[i]==1||s[i]==2&&i>k);
		for (i=1;i<=n;i++) if (s[i]==2)
		{
			cur=ans;
			if (i<=k)
			{cur-=(ll)pss[1][i]*y+(ll)nss[1][i]*x;
			cur+=(ll)pss[0][i]*x+(ll)nss[0][i]*y;

			}
			else
			{
				cur-=(ll)pss[0][i]*x+(ll)nss[0][i]*y;
			cur+=(ll)pss[1][i]*y+(ll)nss[1][i]*x;
			}
			
			if (ans>cur) {puts("ERROR");while(1);}
		}printf("%lld",ans);return 0;
	}
		for (i=1;i<=n;i++) pss[0][i]=pss[0][i-1]+(s[i]==0||s[i]==2&&i>j);
		for (i=1;i<=n;i++) pss[1][i]=pss[1][i-1]+(s[i]==1||s[i]==2&&i<=j);
		for (i=n;i;i--) nss[0][i]=nss[0][i+1]+(s[i]==0||s[i]==2&&i>j);
		for (i=n;i;i--) nss[1][i]=nss[1][i+1]+(s[i]==1||s[i]==2&&i<=j);
		for (i=1;i<=n;i++) if (s[i]==2)
		{
			cur=ans;
			if (i<=j)
			{
				cur-=(ll)pss[0][i]*x+(ll)nss[0][i]*y;
				cur+=(ll)pss[1][i]*y+(ll)nss[1][i]*x;
			}
			else
			{
				cur-=(ll)pss[1][i]*y+(ll)nss[1][i]*x;
				cur+=(ll)pss[0][i]*x+(ll)nss[0][i]*y;
			}
			if (ans>cur) {puts("ERROR");while(1);}
		}*/
	printf("%lld",ans);
}