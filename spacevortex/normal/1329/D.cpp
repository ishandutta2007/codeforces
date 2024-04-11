#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,m,top,ans,S,D,C;
int h[N],len[N],c[30];
int sk[N],sl[N];
char s[N];
int vmx()
{
	int ret=0,i;
	for(i=1;i<=26;i++) ret=max(ret,c[i]);
	return ret;
}
void Solve()
{
	int i,ql,qr;
	memset(c,0,sizeof(c));
	scanf("%s",s+1);
	n=strlen(s+1);
	m=0;
	for(i=1;i<n;i++)
	{
		if(s[i]==s[i+1])
		{
			m++;
			h[m]=s[i]-'a'+1;
			c[h[m]]++;
			len[m]=i;
		}
	}
	S=m;D=0;
	ans=max(vmx(),(S+1)>>1)+1;
	printf("%d\n",ans);
	top=0;
	for(i=1;i<=m;i++)
	{
		len[i]-=D;
		if(S>2*vmx()&&top>0&&sk[top]!=h[i])
		{
			ql=sl[top]+1;qr=len[i];
			printf("%d %d\n",ql,qr);
			c[sk[top]]--;c[h[i]]--;S-=2;
			D+=qr-ql+1;top--;
		}
		else
		{
			top++;sk[top]=h[i];sl[top]=len[i];
		}
	}
	n-=D;
	//puts("OK");
	C=1;
	for(i=1;i<=26;i++)
	{
		if(c[i]>c[C]) C=i;
	}
	m=top;
	for(i=1;i<=top;i++)
	{
		h[i]=sk[i];len[i]=sl[i];
	}
	top=0;D=0;
	for(i=1;i<=m;i++)
	{
		len[i]-=D;
		if(top>0&&((h[i]==C&&sk[top]!=C)||(h[i]!=C&&sk[top]==C)))
		{
			ql=sl[top]+1;qr=len[i];
			printf("%d %d\n",ql,qr);
			D+=qr-ql+1;top--;
		}
		else 
		{
			top++;sk[top]=h[i];sl[top]=len[i];
		}
	}
	for(i=top;i>=1;i--)
	{
		printf("%d %d\n",sl[i],sl[i]);
	}
	D+=top;
	n-=D;
	printf("1 %d\n",n);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) Solve();
	return 0;
}