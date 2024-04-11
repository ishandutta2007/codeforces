#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=100005;
typedef long long LL;
int n,k,lim,m,tp[N],block[N],l,r;
LL a[N],Ans[N],ans,pool[N*3];
int Dec[N*3],Add[N*3];
struct data{int id,l,r;} dat[N],tmp[N];

bool cmp(data a,data b)
{
	return block[a.l]==block[b.l]?a.r<b.r:a.l<b.l;
}

int find(LL x)
{
	l=1,r=*pool;
	while(l<=r)
		pool[mid]<=x?l=mid+1:r=mid-1;
	return l-1;
}

int main()
{
	scanf("%d%d",&n,&k),lim=sqrt(n);
	rep(i,1,n) scanf("%d",&tp[i]);
	rep(i,1,n) if(scanf("%d",&a[i]),tp[i]==2) a[i]=-a[i];
	scanf("%d",&m);
	rep(i,1,m) scanf("%d%d",&dat[i].l,&dat[i].r),dat[i].id=i;
	rep(i,1,n) block[i]=(i-1)/lim+1,a[i]+=a[i-1];
	rep(i,0,n) pool[++*pool]=a[i],pool[++*pool]=a[i]-k,pool[++*pool]=a[i]+k;
	sort(pool+1,pool+1+*pool);
	rep(i,0,n) tmp[i].id=find(a[i]),tmp[i].l=find(a[i]-k),tmp[i].r=find(a[i]+k);
	sort(dat+1,dat+1+m,cmp),l=1,r=0;
	rep(i,1,m)
	{
		while(r<dat[i].r) ++r,++Dec[tmp[r-1].id],ans+=Dec[tmp[r].l],++Add[tmp[r].id];
		while(r>dat[i].r) --Add[tmp[r].id],ans-=Dec[tmp[r].l],--Dec[tmp[r-1].id],--r;
		while(l>dat[i].l) --l,++Add[tmp[l].id],ans+=Add[tmp[l-1].r],++Dec[tmp[l-1].id];
		while(l<dat[i].l) --Dec[tmp[l-1].id],ans-=Add[tmp[l-1].r],--Add[tmp[l].id],++l;
		Ans[dat[i].id]=ans;
	}
	rep(i,1,m) printf("%I64d\n",Ans[i]);
	return 0;
}