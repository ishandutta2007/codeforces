#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int,int> a[60],b[60];
int ans[60][60],ys[60];
int n,c,fh,i,j,k,pos,cnt,ct,tp;
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
	read(n);
	for (i=1;i<=n;i++) {read(a[i].first);a[i].second=a[i].first;}
	while (1)
	{
		for (i=1;i<=n;i++) for (j=a[i].first;j<=a[i].second;j++) ys[j]=i;
		for (i=1;i<=n;i++) if ((a[i].first>1)&&(i<(j=ys[a[i].first-1])))
		{
			++cnt;tp=0;
			for (k=1;k<i;k++) tp+=a[k].second-a[k].first+1;
			if (tp) ans[cnt][++ans[cnt][0]]=tp;
			ans[cnt][++ans[cnt][0]]=a[i].second-a[i].first+1;tp=0;
			for (k=i+1;k<=j;k++) tp+=a[k].second-a[k].first+1;
			ans[cnt][++ans[cnt][0]]=tp;tp=0;
			for (k=j+1;k<=n;k++) tp+=a[k].second-a[k].first+1;
			if (tp) ans[cnt][++ans[cnt][0]]=tp;tp=0;
			for (k=j+1;k<=n;k++) b[++tp]=a[k];
			for (k=i+1;k<j;k++) b[++tp]=a[k];
			b[++tp]=a[j];b[tp].second=a[i].second;//printf("%d\n",a[i].first);
			for (k=1;k<i;k++) b[++tp]=a[k];n=tp;
			for (k=1;k<=n;k++) a[k]=b[k];
			break;
		}if (i>n) break;
		//for (i=1;i<=n;i++) printf("%d-%d ",a[i].first,a[i].second);puts("");
	}
	printf("%d\n",cnt);
	for (i=1;i<=cnt;i++)
	{
		printf("%d ",ans[i][0]);
		for (j=1;j<=ans[i][0];j++) printf("%d ",ans[i][j]);puts("");
	}
}