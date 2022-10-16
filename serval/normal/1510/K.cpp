#include <cstdio>
#include <algorithm>

using namespace std;

const int N=2005;

int n;
int a[N],p[N],ans;

void UD()
{
	for (int i=1;i<=n;i++)
		swap(p[i],p[i+n]);
}
void LR()
{
	for (int i=1;i<=n;i++)
		swap(p[2*i-1],p[2*i]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	ans=-1;
	for (int i=1;i<=2*n;i++)
		p[i]=a[i];
	for (int i=0;i<=2*n;i++)
	{
		bool chk=1;
		for (int j=1;j<2*n;j++)
			chk&=p[j]<p[j+1];
		if (chk)
			if (i<ans||ans==-1)
				ans=i;
		if (i&1)
			LR();
		else
			UD();
		chk=1;
		for (int j=1;j<=2*n;j++)
			chk&=p[j]==a[j];
		if (chk)
			break;
	}
	for (int i=1;i<=2*n;i++)
		p[i]=a[i];
	for (int i=0;i<=2*n;i++)
	{
		bool chk=1;
		for (int j=1;j<2*n;j++)
			chk&=p[j]<p[j+1];
		if (chk)
			if (i<ans||ans==-1)
				ans=i;
		if (i&1)
			UD();
		else
			LR();
		chk=1;
		for (int j=1;j<=2*n;j++)
			chk&=p[j]==a[j];
		if (chk)
			break;
	}
	printf("%d\n",ans);
	return 0;
}