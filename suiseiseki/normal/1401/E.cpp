#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200004;
int n,m,w,h;
namespace DSU{
	int fa[Maxn+5];
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return;
		}
		fa[fa_y]=fa_x;
	}
	void init(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
	}
}
int len;
namespace Segment_Tree{
	struct Segment_Node{
		int sum,lazy;
	}seg[Maxn<<2|5];
	void push_down(int root){
		if(seg[root].lazy==0){
			return;
		}
		if(seg[root<<1].lazy){
			DSU::merge(seg[root<<1].lazy,seg[root].lazy);
		}
		if(seg[root<<1|1].lazy){
			DSU::merge(seg[root<<1|1].lazy,seg[root].lazy);
		}
		if(seg[root<<1].sum){
			seg[root<<1].lazy=seg[root].lazy;
		}
		if(seg[root<<1|1].sum){
			seg[root<<1|1].lazy=seg[root].lazy;
		}
		seg[root].lazy=0;
	}
	void update_1(int x,int a,int root=1,int left=1,int right=len){
		if(left==right){
			seg[root].sum+=a;
			return;
		}
		int mid=(left+right)>>1;
		if(x<=mid){
			update_1(x,a,root<<1,left,mid);
		}
		else{
			update_1(x,a,root<<1|1,mid+1,right);
		}
		seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
	}
	void update_2(int x,int c,int root=1,int left=1,int right=len){
		if(left==right){
			seg[root].lazy=c;
			return;
		}
		push_down(root);
		int mid=(left+right)>>1;
		if(x<=mid){
			update_2(x,c,root<<1,left,mid);
		}
		else{
			update_2(x,c,root<<1|1,mid+1,right);
		}
	}
	void update_3(int l,int r,int c,int root=1,int left=1,int right=len){
		if(seg[root].sum==0){
			return;
		}
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			if(seg[root].lazy){
				DSU::merge(seg[root].lazy,c);
			}
			seg[root].lazy=c;
			return;
		}
		push_down(root);
		int mid=(left+right)>>1;
		update_3(l,r,c,root<<1,left,mid);
		update_3(l,r,c,root<<1|1,mid+1,right);
	}
	int query(int l,int r,int root=1,int left=1,int right=len){
		if(l>right||r<left){
			return 0;
		}
		if(l<=left&&r>=right){
			return seg[root].sum;
		}
		int mid=(left+right)>>1;
		return query(l,r,root<<1,left,mid)+query(l,r,root<<1|1,mid+1,right);
	}
}
vector<int> row,col;
vector<pair<pair<int,int>,pair<int,int> > > line;
vector<pair<pair<int,int>,pair<int,int> > > mp[Maxn+5];
int main(){
	w=h=1000000;
	scanf("%d%d",&n,&m);
	row.push_back(0);
	row.push_back(w);
	col.push_back(0);
	col.push_back(h);
	line.push_back(make_pair(make_pair(0,0),make_pair(w,0)));
	line.push_back(make_pair(make_pair(0,0),make_pair(0,h)));
	line.push_back(make_pair(make_pair(w,0),make_pair(w,h)));
	line.push_back(make_pair(make_pair(0,h),make_pair(w,h)));
	for(int i=1;i<=n;i++){
		int x_1,y_1,x_2,y_2;
		scanf("%d%d%d",&y_1,&x_1,&x_2);
		y_2=y_1;
		row.push_back(x_1);
		col.push_back(y_1);
		row.push_back(x_2);
		col.push_back(y_2);
		line.push_back(make_pair(make_pair(x_1,y_1),make_pair(x_2,y_2)));
	}
	for(int i=1;i<=m;i++){
		int x_1,y_1,x_2,y_2;
		scanf("%d%d%d",&x_1,&y_1,&y_2);
		x_2=x_1;
		row.push_back(x_1);
		col.push_back(y_1);
		row.push_back(x_2);
		col.push_back(y_2);
		line.push_back(make_pair(make_pair(x_1,y_1),make_pair(x_2,y_2)));
	}
	n+=m;
	n+=4;
	sort(row.begin(),row.end());
	sort(col.begin(),col.end());
	row.erase(unique(row.begin(),row.end()),row.end());
	col.erase(unique(col.begin(),col.end()),col.end());
	len=row.size();
	for(int i=0;i<n;i++){
		int x_1=upper_bound(row.begin(),row.end(),line[i].first.first)-row.begin();
		int y_1=upper_bound(col.begin(),col.end(),line[i].first.second)-col.begin();
		int x_2=upper_bound(row.begin(),row.end(),line[i].second.first)-row.begin();
		int y_2=upper_bound(col.begin(),col.end(),line[i].second.second)-col.begin();
		if(x_1==x_2){
			mp[y_1].push_back(make_pair(make_pair(1,i+1),make_pair(x_1,x_2)));
			mp[y_2].push_back(make_pair(make_pair(-1,i+1),make_pair(x_1,x_2)));
		}
		else{
			mp[y_1].push_back(make_pair(make_pair(0,i+1),make_pair(x_1,x_2)));
		}
	}
	DSU::init();
	for(int i=1;i<=(int)col.size();i++){
		sort(mp[i].begin(),mp[i].end(),greater<pair<pair<int,int>,pair<int,int> > >());
	}
	ll ans=0;
	for(int i=1;i<=(int)col.size();i++){
		for(int j=0;j<(int)mp[i].size();j++){
			int op=mp[i][j].first.first,x=mp[i][j].first.second;
			int l=mp[i][j].second.first,r=mp[i][j].second.second;
			if(op==1){
				Segment_Tree::update_2(l,x);
				Segment_Tree::update_1(l,1);
			}
			if(op==0){
				Segment_Tree::update_3(l,r,x);
				ans+=Segment_Tree::query(l,r);
			}
			if(op==-1){
				Segment_Tree::update_2(l,0);
				Segment_Tree::update_1(l,-1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==DSU::find(i)){
			ans++;
		}
	}
	ans-=n;
	printf("%lld\n",ans);
	return 0;
}