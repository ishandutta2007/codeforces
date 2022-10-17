#include <set>
#include <cstdio>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
int p[Maxn+5];
int n,m;
set<int> st[Maxn+5];
struct Segment_Node{
	int lson,rson;
	ll sum;
}seg[Maxn*150+5];
int id_tot;
int f[Maxn+5];
void insert(int x,int a,int &root,int left=0,int right=n){
	if(root==0){
		root=++id_tot;
	}
	seg[root].sum+=a;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		insert(x,a,seg[root].lson,left,mid);
	}
	else{
		insert(x,a,seg[root].rson,mid+1,right);
	}
}
ll query(int l,int r,int &root,int left=0,int right=n){
	if(root==0){
		return 0;
	}
	if(l>right||r<left){
		return 0;
	}
	if(l<=left&&r>=right){
		return seg[root].sum;
	}
	int mid=(left+right)>>1;
	return query(l,r,seg[root].lson,left,mid)+query(l,r,seg[root].rson,mid+1,right);
}
void add(int x,int y,int a){
	for(int i=x;i<=n;i+=(i&(-i))){
		insert(y,a,f[i]);
	}
}
ll sum(int l,int r){
	ll ans=0;
	for(int i=r;i>0;i-=(i&(-i))){
		ans+=query(l,r,f[i]);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	set<int>::iterator it;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!st[a[i]].empty()){
			it=st[a[i]].end();
			it--;
			p[i]=(*it);
		}
		add(i,p[i],i-p[i]);
		st[a[i]].insert(i);
	}
	int op,l,x;
	for(int i=1;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&l,&x);
			it=st[a[l]].find(l);
			it++;
			if(it!=st[a[l]].end()){
				add((*it),p[*it],-((*it)-p[*it]));
				p[*it]=p[l];
				add((*it),p[*it],(*it)-p[*it]);
			}
			st[a[l]].erase(l);
			add(l,p[l],-(l-p[l]));
			a[l]=x;
			st[a[l]].insert(l);
			it=st[a[l]].find(l);
			if(it!=st[a[l]].begin()){
				it--;
				p[l]=(*it);
				it++;
			}
			else{
				p[l]=0;
			}
			add(l,p[l],l-p[l]);
			it++;
			if(it!=st[a[l]].end()){
				add((*it),p[*it],-((*it)-p[*it]));
				p[*it]=l;
				add((*it),p[*it],(*it)-p[*it]);
			}
		}
		else{
			scanf("%d%d",&l,&x);
			printf("%lld\n",sum(l,x));
		}
	}
	return 0;
}