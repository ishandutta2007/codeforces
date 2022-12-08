#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define pii pair<int,int>
#define FF first
#define SS second
using namespace std;

struct node{
	int x,y0,y1;
}p[100005];
struct query{
	int x,p;
}g[200005];
int n,k,c[100050],d[200005],K,sum[100005];
ll ans[100005];
set<pair<int,int> > s;
inline bool operator < (node a,node b){
	return a.x<b.x;
}
inline void change(int x,int p){
	set<pair<int,int> >::iterator it=s.lower_bound(mp(x,-n*2));
	if(it==s.end()){s.insert(mp(x,p));return;}
	int u=(*it).FF,v=(*it).SS;
	if(u!=x){s.insert(mp(x,p));return;}
	s.erase(*it);
	v+=p;
	if(v) s.insert(mp(u,v));
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++){
		int y;
		scanf("%d%d",&p[i].x,&y);
		p[i].y0=y-K+1;p[i].y1=y+1;
	}
	sort(p+1,p+n+1);
	int last=-2e9,l=1,r=0;
	for(int i=1;i<=n;i++){
//		printf("%d %d\n",max(last+1,p[i].x-K+1),p[i].x);
		for(int j=max(last+1,p[i].x-K+1);j<=p[i].x;j++){
//			printf("task:%d\n",j);
			while(r<n&&p[r+1].x<j+K) r++,change(p[r].y0,1),change(p[r].y1,-1);
			while(l<=r&&p[l].x<j) change(p[l].y0,-1),change(p[l].y1,1),l++;
//			printf("%d %d %d\n",l,r,(int)(s.size()));
			int now=0,id=0,k=0;
			for(set<pii>::iterator it=s.begin();it!=s.end();it++){
				k++;int x=(*it).FF,p=(*it).SS;
				ans[now]+=x-id;
				id=x;
				now+=p;
			}
//			puts("");
		}
		last=p[i].x;
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	puts("");
	return 0;
}
/*
5 3
4 5
4 6
5 5
5 6
7 7
*/