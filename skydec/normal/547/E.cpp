#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=710000;
int ST;
struct SA{
	int n;int a[N];
	int sum[N],rank[N],sa[N],tsa[N],trank[N],p;
	int h[N];
	int f[21][410000];
	int bit[N];
	void work(){
		p=0;
		rep(i,1,n){
			rank[i]=a[i];
			sum[a[i]]++;
			if(a[i]>p)p=a[i];
		}
		rep(i,1,p)sum[i]+=sum[i-1];
		rep(i,1,n)sa[sum[a[i]]--]=i;
		rank[sa[1]]=p=1;
		rep(i,2,n){
			if(a[sa[i]]!=a[sa[i-1]])p++;
			rank[sa[i]]=p;
		}
		for(int k=1;k+1<=n&&p!=n;k<<=1){
			rep(i,0,p)sum[i]=0;
			rep(i,1,n)sum[rank[i+k]]++;
			rep(i,1,p)sum[i]+=sum[i-1];
			rep(i,1,n)tsa[sum[rank[i+k]]--]=i;
			
			rep(i,0,p)sum[i]=0;
			rep(i,1,n)sum[rank[i]]++;
			rep(i,1,p)sum[i]+=sum[i-1];
			per(i,n,1)sa[sum[rank[tsa[i]]]--]=tsa[i];
			
			trank[sa[1]]=p=1;
			rep(i,2,n){
				if(rank[sa[i]]!=rank[sa[i-1]]||rank[sa[i]+k]!=rank[sa[i-1]+k])p++;
				trank[sa[i]]=p;
			}
			rep(i,1,n)rank[i]=trank[i];
		}
		p=0;
		rep(i,1,n){
			if(p)p--;
			while(a[i+p]==a[sa[rank[i]-1]+p])p++;
			h[rank[i]]=f[0][rank[i]-1]=p;
		}
		rep(j,1,20){
			rep(i,1,n){
				f[j][i]=f[j-1][i];
				if(i+(1<<(j-1))<=n){
					if(f[j-1][i+(1<<(j-1))]<f[j][i])
					f[j][i]=f[j-1][i+(1<<(j-1))];
				}
			}
		}
		int np=2;int now=0;
		rep(i,1,n){
			if(np==i){now++;np<<=1;}
			bit[i]=now;
		}
	}
	inline int lcp(int a,int b){
		if(a==b)return n-sa[a]+1;
		if(a>b){int tmp=a;a=b;b=tmp;}
		b--;
		return min(f[bit[b-a+1]][a],f[bit[b-a+1]][b-(1<<bit[b-a+1])+1]);
	}
}gt;
int st[N];
int ed[N];
int n,q;
char a[N];
int root[N];
int cl[N*21],cr[N*21],tot,sum[N*21];
void build(int y,int &x,int l,int r,int pos){
	x=++tot;
	sum[x]=sum[y];
	cl[x]=cl[y];cr[x]=cr[y];
	if(l==r){
		sum[x]++;return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)build(cl[y],cl[x],l,mid,pos);
	else build(cr[y],cr[x],mid+1,r,pos);
	sum[x]++;
}
int get(int me,int l,int r,int x,int y){
	if(x>y)return 0;
	if(x<=l&&r<=y)return sum[me];
	int mid=(l+r)>>1;
	int ret=0;
	if(x<=mid)ret+=get(cl[me],l,mid,x,y);
	if(y>mid)ret+=get(cr[me],mid+1,r,x,y);
	return ret;
}
int ask(int x1,int y1,int x2,int y2){
	return get(root[y1],1,gt.n,1,y2)-get(root[y1],1,gt.n,1,x2-1)-(get(root[x1-1],1,gt.n,1,y2)-get(root[x1-1],1,gt.n,1,x2-1));
}
int ED;
int main(){
	//printf("%d MB\n",((&ED)-(&ST))/250000);
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		st[i]=gt.n+1;
		scanf("%s",a+1);
		int len=strlen(a+1);
		rep(j,1,len)gt.a[++gt.n]=a[j];
		ed[i]=gt.n;
		gt.a[++gt.n]='z'+1;
	}
	gt.work();
	
	rep(i,1,gt.n){
			build(root[i-1],root[i],1,gt.n,gt.rank[i]);
	}
	while(q--){
		int _l,_r,k;
		scanf("%d%d%d",&_l,&_r,&k);
		int l=1;int r=gt.rank[st[k]];int bbl=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(gt.lcp(mid,gt.rank[st[k]])>=ed[k]-st[k]+1)bbl=mid,r=mid;
			else l=mid+1;
		}
		if(gt.lcp(l,gt.rank[st[k]])>=ed[k]-st[k]+1)bbl=l;
		l=gt.rank[st[k]];r=gt.n;int bbr=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(gt.lcp(gt.rank[st[k]],mid)>=ed[k]-st[k]+1)bbr=mid,l=mid+1;
			else r=mid;
		}
		if(gt.lcp(gt.rank[st[k]],l)>=ed[k]-st[k]+1)bbr=l;
		
		printf("%d\n",ask(st[_l],ed[_r],bbl,bbr));
	}
	return 0;
}