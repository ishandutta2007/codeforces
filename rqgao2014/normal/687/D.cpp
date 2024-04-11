#include<bits/stdc++.h>
using namespace std;

struct node{
	int u,v,w,num;
}p[1000005];
int n,m,q,next[1005],a[1005];

inline bool operator < (node a,node b){
	return a.w>b.w;
}
inline int find(int x){
	int t=next[x];
	if(next[x]!=x) next[x]=find(next[x]);
	a[x]=a[x]^a[t];
	return next[x];
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w),p[i].num=i;
	sort(p+1,p+m+1);
	for(int i=1;i<=q;i++){
		int l,r;scanf("%d%d",&l,&r);
		for(int i=1;i<=n;i++) next[i]=i,a[i]=0;
		int tot=n-1,ans=-1;
		for(int i=1;i<=m;i++){
			if(p[i].num<l||p[i].num>r) continue;
			int t=find(p[i].u),s=find(p[i].v);
			if(s!=t){
				int d=a[p[i].u]^a[p[i].v]^1;
				next[s]=t;
				a[s]=d;
			}
			else{
				if(a[p[i].u]==a[p[i].v]){ans=p[i].w;break;}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

/*
5 6 5
5 4 86
5 1 0
1 3 38
2 1 33
2 4 28
2 3 40
3 5
2 6
1 3
2 3
1 6
*/