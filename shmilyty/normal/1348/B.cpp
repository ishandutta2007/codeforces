#include<iostream>
#include<cstdio>
using namespace std;
int T,n;
int a[100010],vis[100010],cnt,k;
int b[100010],bnt,c[100010];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		bnt=cnt=0;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if(!vis[a[i]]) {
				vis[a[i]]=1;
				cnt++;
				bnt++;
				b[bnt]=a[i];
			}
		}
		if(cnt>k) {
			puts("-1");
			continue;
		}
		if(cnt<k) {
			int t=1;
			for(int i=1;i<=n&&cnt<k;i++)
				if(!vis[i]) b[++bnt]=i,cnt++;
		}
		int ccnt=n,bbnt=1,nt=0;
		for(int i=1;i<=n;i++) {
			if(a[i]==b[bbnt]){
			++nt;
				c[nt]=a[i];
				bbnt++;
				if(bbnt==k+1) bbnt=1;
			}
			else {
				while(a[i]!=b[bbnt]) {
					c[++nt]=b[bbnt];
					bbnt++;
					if(bbnt==k+1) bbnt=1;
				}
				c[++nt]=b[bbnt];
				bbnt++;
				if(bbnt==k+1) bbnt=1;
			}
		}
		printf("%d\n",nt);
		for(int i=1;i<=nt;i++)
			printf("%d ",c[i]);
		puts("");
	}
	return 0;
}