#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=100005;
int ST;
int a[N];
set<int>pos[N];
int cl[N*150],cr[N*150];LL sum[N*150];int segtot;
int root[N];
int n,Q;
inline void add(int &me,int l,int r,int x,int y,int v){
	if(!me)me=++segtot;
	if(x<=l&&r<=y){
		sum[me]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(cl[me],l,mid,x,y,v);
	if(y>mid)add(cr[me],mid+1,r,x,y,v);
}
inline void newadd(int l,int r,int w){
	//printf("_%d %d %d\n",l,r,w);
	for(;r<=n;r+=(r&(-r))){
		add(root[r],1,n,1,l,w);
	}
}
inline LL ask(int me,int l,int r,int x){
	if(!me)return 0;
	if(l==r)return sum[me];
	int mid=(l+r)>>1;
	if(x<=mid)return sum[me]+ask(cl[me],l,mid,x);
	else return sum[me]+ask(cr[me],mid+1,r,x);
}
inline LL newask(int l,int r){
	LL ans=0;
	for(;r;r-=(r&(-r)))ans+=ask(root[r],1,n,l);
	return ans;
}
inline void modify(int p,int x){
	if(a[p]==x)return;
	int y=a[p];
	set<int>::iterator it=pos[y].find(p);

	if(it!=pos[y].begin()){
		set<int>::iterator pr=it;
		--pr;
		newadd(*pr,p,(*pr)-p);
	}
	set<int>::iterator sf=it;
	++sf;
	if(sf!=pos[y].end()){
		newadd(p,*sf,p-(*sf));
		if(it!=pos[y].begin()){
			set<int>::iterator pr=it;
			--pr;
			newadd(*pr,*sf,(*sf)-(*pr));
		}
	}
	//
	pos[y].erase(p);

	y=x;
	pos[y].insert(p);
	it=pos[y].find(p);
	if(it!=pos[y].begin()){
		set<int>::iterator pr=it;
		--pr;
		newadd(*pr,p,p-(*pr));
	}
	sf=it;
	++sf;
	if(sf!=pos[y].end()){
		newadd(p,*sf,(*sf)-p);
		if(it!=pos[y].begin()){
			set<int>::iterator pr=it;
			--pr;
			newadd(*pr,*sf,(*pr)-(*sf));
		}
	}
	a[p]=y;
}
int pr[N];
int ED;
int main(){
	//printf("%d MB\n",((&ED)-(&ST))/250000);
	scanf("%d%d",&n,&Q);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		pos[a[i]].insert(i);
		if(pr[a[i]]){
			newadd(pr[a[i]],i,i-pr[a[i]]);
		}
		pr[a[i]]=i;
	}
	while(Q--){
		int ty;scanf("%d",&ty);
		if(ty==1){
			int p,x;scanf("%d%d",&p,&x);
			modify(p,x);
		}
		else{
			int l,r;scanf("%d%d",&l,&r);
			printf("%I64d\n",newask(l,r));
		}
	}
	return 0;
}