#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=100005;
struct line{
	int x,t,kd,id;
}a[N];
inline bool cmp(const line &a,const line &b){
	if(a.x-a.t!=b.x-b.t)return a.x-a.t<b.x-b.t;
	return a.x<b.x;
}
int w,h,n;
int id[N];
int q1[N];
int q2[N];
int ansx[N],ansy[N];
int main(){
	scanf("%d%d%d",&n,&w,&h);
	rep(i,1,n){
		scanf("%d%d%d",&a[i].kd,&a[i].x,&a[i].t);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	rep(i,1,n)id[i]=i;
	rep(l,1,n){
		int r=l;
		while(r<n&&a[r+1].x-a[r+1].t==a[l].x-a[l].t)++r;
		q1[0]=0;
		q2[0]=0;
		rep(i,l,r){
			if(a[i].kd==1)q1[++q1[0]]=a[i].id;
			if(a[i].kd==2)q2[++q2[0]]=a[i].id;
		}
		l=r;
		if((!q1[0])||(!q2[0]))continue;
		if(q1[0]<q2[0]){
			rep(i,1,q1[0]){
				int x=q1[q1[0]-i+1];
				id[q2[i]]=x;
				x=q2[q2[0]-i+1];
				id[q1[i]]=x;
			}
			rep(i,q1[0]+1,q2[0]){
				int x=q2[i-q1[0]];
				id[q2[i]]=x;
			}
		}
		else{
			rep(i,1,q2[0]){
				int x=q2[q2[0]-i+1];
				id[q1[i]]=x;
				x=q1[q1[0]-i+1];
				id[q2[i]]=x;
			}
			rep(i,q2[0]+1,q1[0]){
				int x=q1[i-q2[0]];
				id[q1[i]]=x;
			}
		}
	}
	rep(i,1,n){
		if(a[i].kd==1){
			ansx[id[a[i].id]]=a[i].x;
			ansy[id[a[i].id]]=h;
		}
		else{
			ansx[id[a[i].id]]=w;
			ansy[id[a[i].id]]=a[i].x;
		}
	}
	rep(i,1,n)printf("%d %d\n",ansx[i],ansy[i]);
	return 0;
}