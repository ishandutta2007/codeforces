#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int lim=60,maxn=1e5+10;
struct segment_tree{
	int l,r;
	vector<int>v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
int a[maxn];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].v.clear();
	if(l==r){
		t[p].v.push_back(a[l]);
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	t[p].v.resize(t[ls(p)].v.size()+t[rs(p)].v.size());
	merge(t[ls(p)].v.begin(),t[ls(p)].v.end(),t[rs(p)].v.begin(),t[rs(p)].v.end(),t[p].v.begin());
	if(t[p].v.size()>lim)t[p].v.erase(t[p].v.begin()+lim,t[p].v.end());
}
vector<int>ans;
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subseg (l<=t[p].l&&t[p].r<=r)
void query(int p,int l,int r){
	if(no_intersection)return;
	if(is_subseg){
		vector<int>tmp(ans.size()+t[p].v.size());
		merge(ans.begin(),ans.end(),t[p].v.begin(),t[p].v.end(),tmp.begin());
		if(tmp.size()>lim)tmp.erase(tmp.begin()+lim,tmp.end());
		ans=tmp;
		return;
	}
	query(ls(p),l,r);
	query(rs(p),l,r);
}
int m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		build(1,1,n);
		scanf("%d",&m);
		while(m--){
			ri l,r;
			scanf("%d%d",&l,&r);
			ans.clear();
			query(1,l,r);
			int mn=INT_MAX;
			for(ri i=0;i<ans.size();++i)
				for(ri j=i+1;j<ans.size();++j)
					ckmin(mn,ans[i]|ans[j]);
			printf("%d\n",mn);
		}
	}
	return 0;
}