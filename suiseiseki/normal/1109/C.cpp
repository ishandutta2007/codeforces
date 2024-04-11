#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 200000
#define Inf 1000000001
struct Segment_Node{
	int left,right;
	int lc,rc;
	ll lsum,sum;
	bool lazy;
	int v;
}seg[Maxn*20+5];
int root,id_tot;
int new_node(int left,int right){
	seg[++id_tot].lazy=0;
	seg[id_tot].v=0;
	seg[id_tot].left=left;
	seg[id_tot].right=right;
	seg[id_tot].lc=seg[id_tot].rc=0;
	seg[id_tot].lsum=seg[id_tot].sum=0;
	return id_tot;
}
ll mn(ll a,ll b){
	return a<b?a:b;
}
void push_up(int root){
	seg[root].sum=seg[seg[root].lc].sum+seg[seg[root].rc].sum;
	seg[root].lsum=mn(seg[seg[root].lc].lsum,seg[seg[root].lc].sum+seg[seg[root].rc].lsum);
}
void update_node(int root,int v){
	seg[root].sum=1ll*(seg[root].right-seg[root].left+1)*v;
	seg[root].lsum=mn(0ll,seg[root].sum);
	seg[root].lazy=1;
	seg[root].v=v;
}
void push_down(int root){
	if(seg[root].lazy){
		int mid=(seg[root].left+seg[root].right)>>1;
		if(!seg[root].lc){
			seg[root].lc=new_node(seg[root].left,mid);
		}
		if(!seg[root].rc){
			seg[root].rc=new_node(mid+1,seg[root].right);
		}
		update_node(seg[root].lc,seg[root].v);
		update_node(seg[root].rc,seg[root].v);
		seg[root].lazy=0;
	}
}
void update(int root,int left,int right,int v){
	if(seg[root].left==left&&seg[root].right==right){
		update_node(root,v);
		return;
	}
	push_down(root);
	int mid=(seg[root].left+seg[root].right)>>1;
	if(left<=mid){
		if(!seg[root].lc){
			seg[root].lc=new_node(seg[root].left,mid);
		}
		if(right<=mid){
			update(seg[root].lc,left,right,v);
		}
		else{
			update(seg[root].lc,left,mid,v);
		}
	}
	if(right>=mid+1){
		if(!seg[root].rc){
			seg[root].rc=new_node(mid+1,seg[root].right);
		}
		if(left>=mid+1){
			update(seg[root].rc,left,right,v);
		}
		else{
			update(seg[root].rc,mid+1,right,v);
		}
	}
	push_up(root);
}
pair<double,ll> query(int root,int left,int right,ll sum){
	if(seg[root].left==left&&seg[root].right==right){
		if(sum+seg[root].lsum>0){
			return make_pair(-1.0,seg[root].sum);
		}
		if(seg[root].left==seg[root].right||seg[root].lazy){
			return make_pair(seg[root].left-1.0*sum/seg[root].v,seg[root].sum);
		}
	}
	push_down(root);
	int mid=(seg[root].left+seg[root].right)>>1;
	if(left<=mid){
		if(!seg[root].lc){
			seg[root].lc=new_node(seg[root].left,mid);
		}
		if(right<=mid){
			return query(seg[root].lc,left,right,sum);
		}
	}
	if(right>=mid+1){
		if(!seg[root].rc){
			seg[root].rc=new_node(mid+1,seg[root].right);
		}
		if(left>=mid+1){
			return query(seg[root].rc,left,right,sum);
		}
	}
	pair<double,ll> l=query(seg[root].lc,left,mid,sum);
	if(l.first>0){
		return l;
	}
	pair<double,ll> r=query(seg[root].rc,mid+1,right,sum+l.second);
	return make_pair(r.first,l.second+r.second);
}
map<int,int> mp;
int main(){
	seg[0].sum=seg[0].lsum=0;
	root=new_node(1,Inf);
	int q;
	scanf("%d",&q);
	int op,l,r,v;
	mp[0]=mp[Inf+1]=0;
	map<int,int>::iterator it_1,it_2;
	while(q--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&l,&v);
			mp[l]=v;
			it_1=mp.find(l);
			it_1++;
			update(1,l,(it_1->first)-1,v);
		}
		else if(op==2){
			scanf("%d",&l);
			it_1=mp.find(l);
			it_2=it_1;
			it_1--;
			it_2++;
			mp.erase(l);
			update(1,l,(it_2->first)-1,(it_1->second));
		}
		else{
			scanf("%d%d%d",&l,&r,&v);
			if(v==0){
				printf("%d\n",l);
				continue;
			}
			it_1=mp.lower_bound(l);
			l=it_1->first;
			if(l>=r){
				puts("-1");
				continue;
			}
			printf("%.7lf\n",query(1,l,r-1,v).first);
		}
	}
	return 0;
}