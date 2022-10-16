#pragma GCC optimize(3)
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
const ll ll_Inf=0x3f3f3f3f3f3f3f3fll;
const int Mod=1000000007;
const int Maxn=200000;
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
template<typename Elem_1,typename Elem_2>
Elem_1 mn(Elem_1 a,Elem_2 b){
	return a<b?a:b;
}
ll pw[20];
struct Seg_Node{
	int l,r,mid;
	int mn,mn2;
}tree[15][Maxn<<2|5];
int a[Maxn+5];
int tt[5];
void push_up(int flag,int rt){
	int cnt=0;
	tt[++cnt]=tree[flag][rt<<1].mn;
	tt[++cnt]=tree[flag][rt<<1].mn2;
	tt[++cnt]=tree[flag][rt<<1|1].mn;
	tt[++cnt]=tree[flag][rt<<1|1].mn2;
	sort(tt+1,tt+1+cnt);
	tree[flag][rt].mn=tt[1];
	tree[flag][rt].mn2=tt[2];
	return;
}
void build(int flag,int rt,int l,int r){
	tree[flag][rt].l=l;
	tree[flag][rt].r=r;
	if(l==r){
		int tt=a[l]/pw[flag];
		if(tt%10==0){
			tree[flag][rt].mn=Inf;
			tree[flag][rt].mn2=Inf;
		}
		else{
			tree[flag][rt].mn=a[l];
			tree[flag][rt].mn2=Inf;
		}
		return;
	}
	int mid=tree[flag][rt].mid=(l+r)>>1;
	build(flag,rt<<1,l,mid);
	build(flag,rt<<1|1,mid+1,r);
	push_up(flag,rt);
	return ;
}
void update(int flag,int rt,int pos,int val){
	if(tree[flag][rt].l==tree[flag][rt].r){
		tree[flag][rt].mn=val;
		tree[flag][rt].mn2=Inf;
		return;
	}
	if(pos<=tree[flag][rt].mid){
		update(flag,rt<<1,pos,val);
	}
	else{
		update(flag,rt<<1|1,pos,val);
	}
	push_up(flag,rt);
}
pair<int,int> query(int flag,int rt,int l,int r){
	if(tree[flag][rt].l>r&&tree[flag][rt].r<l){
		return make_pair(Inf,Inf);
	}
	if(tree[flag][rt].l>=l&&tree[flag][rt].r<=r){
		return make_pair(tree[flag][rt].mn,tree[flag][rt].mn2);
	}
	pair<int,int> ans=make_pair(Inf,Inf);
	if(tree[flag][rt].mid>=l) {
		pair<int,int> tp=query(flag,rt<<1,l,r);
		ans=tp;
	}
	if(tree[flag][rt].mid<r){
		pair<int,int> tp=query(flag,rt<<1|1,l,r);
		int cnt=0;
		tt[++cnt]=tp.first;
		tt[++cnt]=tp.second;
		tt[++cnt]=ans.first;
		tt[++cnt]=ans.second;
		sort(tt+1,tt+1+cnt);
		ans.first=tt[1];
		ans.second=tt[2];
	}
	return ans;
}
int main(){
	int n,m;
	read(n),read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	pw[1]=1;
	for(int i=2;i<=10;i++){
		pw[i]=pw[i-1]*10;
	}
	for(int i=1;i<=10;i++){
		build(i,1,1,n);
	}
	int op,x,y;
	int tmp;
	pair<int,int> tt;
	while(m--){
		read(op),read(x),read(y);
		if(op==1){
			for(int i=1;i<=10;i++){
				tmp=y/pw[i];
				if(tmp%10!=0){
					update(i,1,x,y);
				}
				else{
					update(i,1,x,Inf);
				}
			}
		}
		else{
			ll ans=ll_Inf;
			for(int i=1;i<=10;i++){
				tt=query(i,1,x,y);
				if(tt.first==Inf||tt.second==Inf){
					continue;
				}
				else{
					ans=mn(ans,1ll*tt.first+tt.second);
				}
			}
			if(ans==ll_Inf){
				puts("-1");
			}
			else{
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}