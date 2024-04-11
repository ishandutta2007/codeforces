#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
LL l[N],r[N];int n,m;
struct jb{
	LL x;int id;
}v[N];
inline bool cmp2(const jb &a,const jb &b){return a.x<b.x;}
struct need{
	LL l,r;int id;
}b[N];
inline bool cmp(const need &a,const need &b){
	if(a.r!=b.r)return a.r<b.r;
	return a.l<b.l;
}
inline bool operator <(const jb &a,const jb &b){
	if(a.x==b.x)return a.id<b.id;
	return a.x<b.x;
}
set<jb> wei;
int ans[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%I64d%I64d",&l[i],&r[i]);
	rep(i,1,n-1){
		b[i].l=l[i+1]-r[i];
		b[i].r=r[i+1]-l[i];
		b[i].id=i;
	}
	sort(b+1,b+1+n-1,cmp);
	rep(i,1,m){scanf("%I64d",&v[i].x);v[i].id=i;}
	sort(v+1,v+1+m,cmp2);
	int j=1;
	jb da;da.x=(LL)5e18;
	wei.insert(da);
	rep(i,1,n-1){
		while(v[j].x<=b[i].r&&j<=m){
			wei.insert(v[j]);
			j++;
		}
		jb uu;uu.x=b[i].l;uu.id=-1;
		jb ap=*wei.lower_bound(uu);
		if(ap.x>b[i].r){
			printf("No\n");
			return 0;
		}
		ans[b[i].id]=ap.id;
		wei.erase(wei.find(ap));
	}
	printf("Yes\n");
	rep(i,1,n-1)printf("%d ",ans[i]);
	return 0;
}