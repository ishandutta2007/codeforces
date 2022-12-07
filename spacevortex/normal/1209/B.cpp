#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m=5e4,ans=0;
int val[N];
char s[N];
int main()
{
	int wi,i,j,st,der,w;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(wi=1;wi<=n;wi++)
	{
		scanf("%d%d",&der,&st);
		w=s[wi]-'0';
		for(i=0;i<st;i++) val[i]+=w;
		//printf("P%d %d\n",st,w);
		for(i=st;i<=m;i+=der)
		{
			w^=1;
			for(j=0;j<der;j++) val[i+j]+=w;
		}
	}
	for(i=0;i<=m;i++) ans=max(ans,val[i]);
	printf("%d",ans);
}