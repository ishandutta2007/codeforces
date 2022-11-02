#include<bits/stdc++.h>
#define N 600005
#define M 1200005
#define inf 1000000000
using namespace std;
int i,j,k,l,s[N],n,m,ans,ans1,da[N],last[N],Next[M],to[M],q[N],fa[N],tot,r;
int si[N],dis[N];
int x[N],y[N],ans2,ans3,Fa[N];
struct node {
	int x,y;
}b[M];
inline int get(int x) {
	if (Fa[x]==x) return x;
	return Fa[x]=get(Fa[x]);
}
inline void add(int x,int y) {
	Next[++tot]=last[x]; last[x]=tot; to[tot]=y;
}
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]),add(x[i],y[i]),add(y[i],x[i]),si[x[i]]++,si[y[i]]++;
	l=0,r=1; q[1]=1; dis[1]=1;
	while (l<r) {
		int k=q[++l];
		for (int i=last[k];i;i=Next[i]) {
			if (!dis[to[i]]) fa[q[++r]=to[i]]=k,dis[to[i]]=dis[k]+1;
		}
	}
	if (!dis[n]) dis[n]=inf;
	ans=dis[n]-1;
	ans1=0;
	int bb=0;
	for (i=1;i<=n;i++) Fa[i]=i;
	for (i=2;i<n;i++) if (dis[i]>2) {
		bb=1;
	}
	if (bb) {
		for (i=2;i<n;i++) if (dis[i]==3) {
			if (ans>4) ans=4,ans1=i;
		}
		if (!ans1) {
			int x=n;
			for (i=ans+1;i;i--) da[i]=x,x=fa[x];
		}
		else {
			ans=4;
			da[1]=1;
			da[2]=fa[ans1];
			da[3]=ans1;
			da[4]=1;
			da[5]=n;
		}
	}
	else {
		if (ans<=5) {
			int x=n;
			for (i=ans+1;i;i--) da[i]=x,x=fa[x];
		}
		else {
			for (i=2;i<n&&!ans1;i++) if (dis[i]) {
				for (j=last[i];j&&!ans1;j=Next[j]) {
					if (to[j]==1) continue;
					if (si[i]!=si[to[j]]) {
						for (k=last[i];k;k=Next[k]) s[to[k]]++;
						for (k=last[to[j]];k;k=Next[k]) s[to[k]]--;
						for (k=last[i];k;k=Next[k]) if (to[k]!=to[j]&&s[to[k]]) {
							ans1=to[k]; 
							ans2=i,ans3=to[j];
							break;
						}
						if (ans1) continue;
						for (k=last[to[j]];k;k=Next[k]) if (to[k]!=i&&s[to[k]]) {
							ans1=to[k]; 
							ans2=i,ans3=to[j];
							break;
						}
						s[to[j]]=s[i]=0;
					}
					else {
						if (get(i)==get(to[j])) continue;
						for (k=last[i];k;k=Next[k]) s[to[k]]++;
						for (k=last[to[j]];k;k=Next[k]) s[to[k]]--;
						for (k=last[i];k;k=Next[k]) if (to[k]!=to[j]&&s[to[k]]) {
							ans1=to[k]; 
							ans2=i,ans3=to[j];
							break;
						}
						if (ans1) continue;
						for (k=last[to[j]];k;k=Next[k]) if (to[k]!=i&&s[to[k]]) {
							ans1=to[k]; 
							ans2=i,ans3=to[j];
							break;
						}
						s[to[j]]=s[i]=0;
						if (!ans1) Fa[get(i)]=get(to[j]);
					}
				}
			}
			if (!ans1) {
				if (ans==inf-1) return puts("-1"),0;
				int x=n;
				for (i=ans+1;i;i--) da[i]=x,x=fa[x];
				printf("%d\n",ans);
				for (i=1;i<=ans+1;i++) printf("%d ",da[i]);
				return 0;
			}
				
			ans=5;
			da[1]=1;
			int bb=0;
			for (i=last[ans2];i;i=Next[i]) if (to[i]==ans1) bb=1;
			if (bb) swap(ans2,ans3);
			da[2]=ans2;
			da[3]=ans3;
			da[4]=ans1;
			da[5]=ans2;
			da[6]=n;
		}
	}
	if (ans==inf-1) return puts("-1"),0;
	printf("%d\n",ans);
	for (i=1;i<=ans+1;i++) printf("%d ",da[i]);
}