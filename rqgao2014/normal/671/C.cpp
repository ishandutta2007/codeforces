#include<cstdio>
#include<vector>
#define vi vector<int>
#define ll long long
#define ls k<<1
#define rs k<<1|1
using namespace std;

const int m=200000,M=200006,N=800006;
int n,a[M],l[M],r[M],dl[M],dr[M];
ll ans=0,res;
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
namespace seg{
	int mx[N],mn[N],flag[N],si[N];
	ll p[N];
	inline void upt(int k){
		mx[k]=max(mx[ls],mx[rs]);
		mn[k]=min(mn[ls],mn[rs]);
		p[k]=p[ls]+p[rs];
	}
	inline void pushdown(int l,int r,int k){
		if(!flag[k]) return;
		int mid=l+r>>1;
		flag[ls]=flag[rs]=mn[rs]=mx[rs]=mn[ls]=mx[ls]=flag[k];
		p[ls]=(ll)flag[k]*si[ls];
		p[rs]=(ll)flag[k]*si[rs];
		flag[k]=0;
	}
	inline ll get(int l,int r,int x,int y,int k,int b){
		if(mn[k]>=b)return (ll)b*(y-x+1);
		if(l==x&&r==y){
			if(mx[k]<=b){
//				printf("min %d %d %d\n",l,r,p[k]);
				ll tmp=p[k];
				flag[k]=mx[k]=mn[k]=b;
				p[k]=(ll)b*si[k];
				return tmp;
			}
		}
		pushdown(l,r,k);
		int mid=l+r>>1;ll res=0;
		if(x<=mid) res+=get(l,mid,x,min(mid,y),ls,b);
		if(y>mid) res+=get(mid+1,r,max(mid+1,x),y,rs,b);
		upt(k);
		return res;
	}
	inline void build(int l,int r,int k){
		si[k]=r-l+1;
		if(l==r){mn[k]=mx[k]=p[k]=l-1;return;}
		int mid=l+r>>1;
		build(l,mid,ls);build(mid+1,r,rs);
		upt(k);
	}
};
using namespace seg;
vi f[M];

inline void add(int x,int y,int num){
	ll tmp=(ll)y*(y-x+1)-get(1,n,x,y,1,y);
	if(tmp<0) return;
//	cout<<num<<" ("<<x<<","<<y<<") "<<(ll)tmp<<endl;
//	res+=tmp;
	ans=ans+(ll)num*tmp;
}

int main(){
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j+=i) f[j].push_back(i);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=f[a[i]].size()-1;~j;j--){
			int t=f[a[i]][j];
			if(l[t]&&!dl[t]) dl[t]=i;
			if(!l[t])l[t]=i;
			dr[t]=r[t];r[t]=i;
		}
	build(1,n,1);
	for(int i=m;i;i--){
		if(l[i]<r[i]-1)add(l[i]+1,r[i]-1,i);
		if(dl[i]&&dl[i]<n)add(dl[i]+1,n,i);
		if(dr[i]>1)add(1,dr[i]-1,i);
	}
//	cout<<res<<endl;
	printf("%I64d\n",ans);
	return 0;
}