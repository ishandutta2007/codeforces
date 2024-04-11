#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
const int Inf=0x7f7f7f7f;
struct Node{
	int x,y;
	friend bool operator <(Node a,Node b){
		return a.x-a.y>b.x-b.y;
	}
}a[Maxn+5];
int n,q;
map<pair<int,int>,bool> mp;
struct Segment_Node{
	int tag;
	pair<int,int> minn[Maxn<<2|5];
	pair<int,int> query(int l,int r,int root=1,int left=1,int right=n){
		if(l>r||l>right||r<left){
			return make_pair(Inf,-1);
		}
		if(l<=left&&r>=right){
			return minn[root];
		}
		int mid=(left+right)>>1;
		return min(query(l,r,root<<1,left,mid),query(l,r,root<<1|1,mid+1,right));
	}
	void update(int x,int root=1,int left=1,int right=n){
		if(left==right){
			minn[root]=make_pair(Inf,-1);
			return;
		}
		int mid=(left+right)>>1;
		if(x<=mid){
			update(x,root<<1,left,mid);
		}
		else{
			update(x,root<<1|1,mid+1,right);
		}
		minn[root]=min(minn[root<<1],minn[root<<1|1]);
	}
	void build(int op,int root=1,int left=1,int right=n){
		if(left==right){
			minn[root].second=left;
			if(op==0){
				minn[root].first=a[left].x;
			}
			else{
				minn[root].first=a[left].y;
			}
			return;
		}
		int mid=(left+right)>>1;
		build(op,root<<1,left,mid);
		build(op,root<<1|1,mid+1,right);
		minn[root]=min(minn[root<<1],minn[root<<1|1]);
	}
}seg[2];
int d[Maxn+5];
int s[Maxn+5],s_len;
int t[Maxn+5],t_len;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		mp[make_pair(a[i].x,a[i].y)]=1;
	}
	mp[make_pair(0,0)]=1;
	sort(a+1,a+1+n);
	seg[0].build(0);
	seg[1].build(1);
	for(int i=n;i>0;i--){
		d[n-i+1]=a[i].x-a[i].y;
	}
	int delta=0;
	s[++s_len]=-1;
	t[++t_len]=-1;
	for(int i=1;i<=n;i++){
		int pos=lower_bound(d+1,d+1+n,delta)-d;
		pos=n-pos+1;
		pair<int,int> l_ans=seg[0].query(1,pos-1),r_ans=seg[1].query(pos,n);
		l_ans.first-=seg[0].tag;
		r_ans.first-=seg[1].tag;
		pair<int,int> minn=min(l_ans,r_ans);
		int id=minn.second;
		if(a[id].x-a[id].y==delta){
			if(s[s_len]!=a[id].x&&t[t_len]!=a[id].y){
				seg[0].tag++;
				s[++s_len]=a[id].x;
				seg[1].tag++;
				t[++t_len]=a[id].y;
			}
		}
		else if(a[id].x-a[id].y>delta){
			if(s[s_len]!=a[id].x){
				delta++;
				seg[0].tag++;
				s[++s_len]=a[id].x;
			}
		}
		else{
			if(t[t_len]!=a[id].y){
				delta--;
				seg[1].tag++;
				t[++t_len]=a[id].y;
			}
		}
		seg[0].update(id);
		seg[1].update(id);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(mp.count(make_pair(x,y))>0){
			puts("LOSE");
			continue;
		}
		int pos_x=lower_bound(s+1,s+1+s_len,x)-s,pos_y=lower_bound(t+1,t+1+t_len,y)-t;
		if(s[pos_x]==x||t[pos_y]==y){
			puts("WIN");
			continue;
		}
		x-=pos_x;
		y-=pos_y;
		if(x==y){
			puts("LOSE");
		}
		else{
			puts("WIN");
		}
	}
	return 0;
}