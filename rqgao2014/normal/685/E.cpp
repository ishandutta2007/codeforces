#include<bits/stdc++.h>
using namespace std;

struct node{
	int l,r,s,t,num;
}p[200005];
int n,m,q,u[200005],v[200005],dis[1005][1005],ans[200005];
inline bool operator < (node a,node b){
	return a.l>b.l;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	for(int i=1;i<=q;i++) scanf("%d%d%d%d",&p[i].l,&p[i].r,&p[i].s,&p[i].t),p[i].num=i;
	sort(p+1,p+q+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(m+1);
	int k=0;
	for(int i=m;i;i--){
		dis[u[i]][v[i]]=dis[v[i]][u[i]]=i;
		for(int t=1;t<=n;t++)
			dis[v[i]][t]=dis[u[i]][t]=min(dis[u[i]][t],dis[v[i]][t]);
		while(k<q&&p[k+1].l==i) k++,ans[p[k].num]=(dis[p[k].s][p[k].t]<=p[k].r);
	}
	for(int i=1;i<=q;i++) if(ans[i]) puts("Yes"); else puts("No");
	return 0;
}
/*
5 4 6
1 2
2 3
3 4
3 5
1 3 1 4
1 3 2 4
1 4 5 4
1 4 4 1
2 3 1 4
2 2 2 3
*/