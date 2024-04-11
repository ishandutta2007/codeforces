#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2;
pair<int,int> pre[N];
int a[N];
int n,m,c,fh,i,t,j,cnt,lst,tp;
inline void read(int &x)
{
	c=getchar();fh=1;
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
	read(t);
	while (t--)
	{
		read(n);read(m);cnt=m;lst=-1e9;tp=0;
		c=getchar();while ((c!='W')&&(c!='L')) c=getchar();
		a[1]=(c=='W');
		for (i=2;i<=n;i++) a[i]=(getchar()=='W');
		for (i=1;i<=n;i++) cnt+=a[i];
		if (cnt>=n)
		{
			printf("%d\n",(n<<1)-1);
			continue;
		}
		for (i=1;i<=n;i++)
		{
			if (a[i]) {pre[++tp]=make_pair(i-lst-1,lst<0? i:lst);lst=i;}
		}
		if (lst<0)
		{
			if (m) printf("%d\n",(m<<1)-1); else puts("0");continue;
		}
		pre[++tp]=make_pair(1e8,lst);
		sort(pre+1,pre+tp+1);
		//for (i=1;i<=tp;i++) printf("%d ",pre[i].second);puts("");
		pre[tp-1].first=n-lst;pre[tp].first=pre[tp].second-1;
		for (i=1;(i<tp)&&(m>=pre[i].first);i++)
		{
			for (j=1;j<=pre[i].first;j++) a[pre[i].second+j]=1;m-=pre[i].first;
		}//printf("%d %d\n",i,m);
		if (i==tp) for (j=1;(j<=m)&&(j<pre[i].second);j++) a[pre[i].second-j]=1;
		else if (i<=tp) for (j=1;j<=m;j++) a[pre[i].second+j]=1;
		//for (i=1;i<=n;i++) printf("%d ",a[i]);puts("");
		cnt=0;
		for (i=1;i<=n;i++) if (a[i]) cnt+=1+a[i-1];
		printf("%d\n",cnt);
	}
}