#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int MAXN=210000;
int n,b,q;
struct Aline{
	int pos,l,r,dir;
	bool kind;
	inline void mk(int x1,int y1,int x2,int y2){
		if(x1==x2){
			pos=x1;dir=1;
			if(y1>y2){swap(y1,y2);dir*=-1;}
			l=y1;r=y2;
			kind=0;// ---
		}
		else{
			pos=y1;dir=1;
			if(x1>x2){swap(x1,x2);dir*=-1;}
			l=x1;r=x2;
			kind=1;// |
		}
	}
}a[MAXN];
inline bool cmp(const int &x,const int &y){return a[x].pos<a[y].pos;}
struct seg{
	vector<int>q[MAXN*4];
	bool kind;
	
	void add(int me,int l,int r,int x,int y,int v){
		if(x<=l&&r<=y){
			q[me].pb(v);
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)add(me*2,l,mid,x,y,v);
		if(y>mid)add(me*2+1,mid+1,r,x,y,v);
	}
	
	void work(int me,int l,int r){
		if(S(q[me]))sort(q[me].begin(),q[me].end(),cmp);
		if(l==r)return;
		int mid=(l+r)>>1;
		work(me*2,l,mid);
		work(me*2+1,mid+1,r);
	}
	
	inline void build(){
		rep(i,1,n)if(kind==a[i].kind)
		add(1,0,b,a[i].l,a[i].r,i);
		work(1,0,b);
	}
	int ans;
	
	void get_aft(int me,int y){
		int l=0;int r=S(q[me])-1;
		while(l<r){
			int mid=(l+r)>>1;
			int x=q[me][mid];
			if(a[x].pos>=y){
				if(ans==-1||a[ans].pos>a[x].pos)ans=x;
				r=mid;
			}
			else l=mid+1;
		}
		int x=q[me][l];
		if(a[x].pos>=y){
			if(ans==-1||a[ans].pos>a[x].pos)ans=x;
		}
	}
	
	void aft(int me,int l,int r,int x,int y){
		if(S(q[me]))get_aft(me,y);
		if(l==r)return;
		int mid=(l+r)>>1;
		if(x<=mid)aft(me*2,l,mid,x,y);
		else aft(me*2+1,mid+1,r,x,y);
	}
	
	int after(int x,int y){
		ans=-1;
		aft(1,0,b,x,y);
		return ans;
	}
	
	void get_bef(int me,int y){
		int l=0;int r=S(q[me])-1;
		while(l<r){
			int mid=(l+r)>>1;
			int x=q[me][mid];
			if(a[x].pos<=y){
				if(ans==-1||a[ans].pos<a[x].pos)ans=x;
				l=mid+1;
			}
			else r=mid;
		}
		int x=q[me][l];
		if(a[x].pos<=y){
			if(ans==-1||a[ans].pos<a[x].pos)ans=x;
		}
	}
	void bef(int me,int l,int r,int x,int y){
		if(S(q[me]))get_bef(me,y);
		if(l==r)return;
		int mid=(l+r)>>1;
		if(x<=mid)bef(me*2,l,mid,x,y);
		else bef(me*2+1,mid+1,r,x,y);
	}
	
	int before(int x,int y){
		ans=-1;
		bef(1,0,b,x,y);
		return ans;
	}
}shu,heng;
set<pii> sshu[MAXN],hheng[MAXN];
//------------------------------------------------------------------------------------------------------------------------------
const LL limit=(LL)1e16;
struct Tree{
	//    Node[n+1]: 
	int go[54][MAXN];
	LL cost[54][MAXN];
	void build(){
		rep(i,1,n)
		if(a[i].kind==0){
			if(a[i].dir==1){
				int uccu=heng.after(a[i].pos,a[i].r);set<pii>::iterator bg;
				bg=sshu[a[i].pos].lower_bound(pii(a[i].r,n+2));
				if(bg==sshu[a[i].pos].end()&&uccu==-1){go[0][i]=n+1;cost[0][i]=limit;continue;}
				
				if(uccu==-1){
					int node=(*bg).se;go[0][i]=node;if(a[node].dir==1)cost[0][i]=a[node].r-a[i].r;else cost[0][i]=a[node].l-a[i].r;
					continue;
				}
				
				if(bg==sshu[a[i].pos].end()){
					go[0][i]=uccu;cost[0][i]=a[uccu].pos-a[i].r;if(a[uccu].dir==1)cost[0][i]+=a[uccu].r-a[i].pos;else cost[0][i]+=a[i].pos-a[uccu].l;
					continue;
				}
				
				int node=(*bg).se;
				if(a[node].r<a[uccu].pos){
					go[0][i]=node;if(a[node].dir==1)cost[0][i]=a[node].r-a[i].r;else cost[0][i]=a[node].l-a[i].r;
					continue;
				}
				
				else{
					go[0][i]=uccu;cost[0][i]=a[uccu].pos-a[i].r;if(a[uccu].dir==1)cost[0][i]+=a[uccu].r-a[i].pos;else cost[0][i]+=a[i].pos-a[uccu].l;
					continue;
				}
			}
			else{
				int uccu=heng.before(a[i].pos,a[i].r);
				set<pii>::iterator bg,tmp;
				bg=sshu[a[i].pos].lower_bound(pii(a[i].r,0));
				
				if(bg==sshu[a[i].pos].begin()&&uccu==-1){go[0][i]=n+1;cost[0][i]=limit;continue;}
				
				if(bg==sshu[a[i].pos].begin()){
					go[0][i]=uccu;cost[0][i]=a[i].l-a[uccu].pos;
					if(a[uccu].dir==1)cost[0][i]+=a[uccu].r-a[i].pos;else cost[0][i]+=a[i].pos-a[uccu].l;
					continue;
				}
				tmp=bg;--tmp;int node=(*tmp).se;
				
				if(uccu==-1){
					go[0][i]=node;if(a[node].dir==1)cost[0][i]=a[i].l-a[node].r;else cost[0][i]=a[i].l-a[node].l;
					continue;
				}
				
				if(a[node].r>a[uccu].pos){
					go[0][i]=node;if(a[node].dir==1)cost[0][i]=a[i].l-a[node].r;else cost[0][i]=a[i].l-a[node].l;
					continue;
				}
				
				else{
					go[0][i]=uccu;cost[0][i]=a[i].l-a[uccu].pos;
					if(a[uccu].dir==1)cost[0][i]+=a[uccu].r-a[i].pos;else cost[0][i]+=a[i].pos-a[uccu].l;
					continue;
				}
			}
		}
		else{
			if(a[i].dir==1){
				// --------->
				int uccu=shu.after(a[i].pos,a[i].r);
				set<pii>::iterator bg;
				bg=hheng[a[i].pos].lower_bound(pii(a[i].r,n+2));
				
				if(bg==hheng[a[i].pos].end()&&uccu==-1){
					go[0][i]=n+1;cost[0][i]=limit;continue;
				}
				
				if(bg==hheng[a[i].pos].end()){
					go[0][i]=uccu;cost[0][i]=a[uccu].pos-a[i].r;
					if(a[uccu].dir==1)cost[0][i]+=a[uccu].r-a[i].pos;else cost[0][i]+=a[i].pos-a[uccu].l;
					continue;
				}
				int node=(*bg).se;
				
				if(uccu==-1){
					go[0][i]=node;if(a[node].dir==1)cost[0][i]=a[node].r-a[i].r;else cost[0][i]=a[node].l-a[i].r;
					continue;
				}
				
				if(a[uccu].pos<a[node].l){
					go[0][i]=uccu;cost[0][i]=a[uccu].pos-a[i].r;
					if(a[uccu].dir==1)cost[0][i]+=a[uccu].r-a[i].pos;else cost[0][i]+=a[i].pos-a[uccu].l;
					continue;
				}
				else{
					go[0][i]=node;if(a[node].dir==1)cost[0][i]=a[node].r-a[i].r;else cost[0][i]=a[node].l-a[i].r;
					continue;
				}
			}
			else{
				// <-------
				int uccu=shu.before(a[i].pos,a[i].l);
				set<pii>::iterator bg,tmp;;
				bg=hheng[a[i].pos].lower_bound(pii(a[i].r,0));
				if(bg==hheng[a[i].pos].begin()&&uccu==-1){
					go[0][i]=n+1;cost[0][i]=limit;continue;
				}
				
				if(bg==hheng[a[i].pos].begin()){
					go[0][i]=uccu;cost[0][i]=a[i].l-a[uccu].pos;
					if(a[uccu].dir==1)cost[0][i]+=a[uccu].r-a[i].pos;else cost[0][i]+=a[i].pos-a[uccu].l;
					continue;
				}
				
				tmp=bg;--tmp;
				int node=(*tmp).se;
				if(uccu==-1){
					go[0][i]=node;if(a[node].dir==1)cost[0][i]=a[i].l-a[node].r;else cost[0][i]=a[i].l-a[node].l;
					continue;
				}
				
				if(a[node].l>a[uccu].pos){
					go[0][i]=node;if(a[node].dir==1)cost[0][i]=a[i].l-a[node].r;else cost[0][i]=a[i].l-a[node].l;
					continue;
				}
				else{
					go[0][i]=uccu;cost[0][i]=a[i].l-a[uccu].pos;
					if(a[uccu].dir==1)cost[0][i]+=a[uccu].r-a[i].pos;else cost[0][i]+=a[i].pos-a[uccu].l;
					continue;
				}
			}
		}
		go[0][n+1]=n+1;
		cost[0][n+1]=1;
		rep(j,1,53)rep(i,1,n+1){
			cost[j][i]=min(cost[j-1][i]+cost[j-1][go[j-1][i]],limit);
			go[j][i]=go[j-1][go[j-1][i]];
		}
	}
}gt;		
//------------------------------------------------------------------------------------------------------------------------------
inline void start(int me,LL t){
	for(int j=53;j>=0;j--)if(t>=gt.cost[j][me]){
		t-=gt.cost[j][me];me=gt.go[j][me];
	}
	//printf("__%d %I64d\n",me,t);
	if(gt.go[0][me]==n+1){
		if(a[me].kind==0){
			if(a[me].dir==1)printf("%d %I64d\n",a[me].pos,min(a[me].r+t,1ll*b));
			else printf("%d %I64d\n",a[me].pos,max(0ll,a[me].l-t));
		}
		else{
			if(a[me].dir==1)printf("%I64d %d\n",min(a[me].r+t,b*1ll),a[me].pos);
			else printf("%I64d %d\n",max(0ll,a[me].l-t),a[me].pos);
		}
		return;
	}
	
	int node=gt.go[0][me];
	//printf("__%d %I64d %d\n",me,t,node);
	if(a[me].kind==a[node].kind){
		if(a[me].kind==1){
			if(a[me].dir==-1)printf("%I64d %d\n",a[me].l-t,a[me].pos);
			else printf("%I64d %d\n",a[me].r+t,a[me].pos);
		}
		else{
			if(a[me].dir==-1)printf("%d %I64d\n",a[me].pos,a[me].l-t);
			else printf("%d %I64d\n",a[me].pos,a[me].r+t);
		}
	}
	else{
		if(a[me].kind==0){
			if(a[me].dir==1){
				if(a[node].pos-a[me].r>=t){printf("%d %I64d\n",a[me].pos,a[me].r+t);return;}
				else{
					t-=(a[node].pos-a[me].r);
					if(a[node].dir==1){printf("%I64d %d\n",a[me].pos+t,a[node].pos);return;}
					else {printf("%I64d %d\n",a[me].pos-t,a[node].pos);return;}
				}
			}
			else{
				if(a[me].l-a[node].pos>=t){printf("%d %I64d\n",a[me].pos,a[me].l-t);return;}
				else{
					t-=(a[me].l-a[node].pos);
					if(a[node].dir==1){printf("%I64d %d\n",a[me].pos+t,a[node].pos);return;}
					else {printf("%I64d %d\n",a[me].pos-t,a[node].pos);return;}
				}
			}
		}
		else{
			if(a[me].dir==1){
				if(a[node].pos-a[me].r>=t){printf("%I64d %d\n",a[me].r+t,a[me].pos);return;}
				else{
					t-=(a[node].pos-a[me].r);
					if(a[node].dir==1){printf("%d %I64d\n",a[node].pos,a[me].pos+t);return;}
					else {printf("%d %I64d\n",a[node].pos,a[me].pos-t);return;}
				}
			}
			else{
				if(a[me].l-a[node].pos>=t){printf("%I64d %d\n",a[me].l-t,a[me].pos);return;}
				else{
					t-=(a[me].l-a[node].pos);
					if(a[node].dir==1){printf("%d %I64d\n",a[node].pos,a[me].pos+t);return;}
					else {printf("%d %I64d\n",a[node].pos,a[me].pos-t);return;}
				}
			}
		}
	}	
}

inline bool tp_online(int x,int y,LL t){
	set<pii>::iterator bg;
	bg=sshu[x].lower_bound(pii(y,0));
	if(bg!=sshu[x].end()){
		int uccu=(*bg).se;
		if(a[uccu].l<=y){
			if(a[uccu].dir==1){
				if(a[uccu].r-y>=t){printf("%d %I64d\n",x,y+t);return 1;}
				else {start(uccu,t-(a[uccu].r-y));return 1;}
			}
			else{
				if(y-a[uccu].l>=t){printf("%d %I64d\n",x,y-t);return 1;}
				else {start(uccu,t-(y-a[uccu].l));return 1;}
			}
		}
	}
	
	bg=hheng[y].lower_bound(pii(x,0));
	if(bg!=hheng[y].end()){
		int uccu=(*bg).se;
		if(a[uccu].l<=x){
			if(a[uccu].dir==1){
				if(a[uccu].r-x>=t){printf("%I64d %d\n",x+t,y);return 1;}
				else {start(uccu,t-(a[uccu].r-x));return 1;}
			}
			else{
				if(x-a[uccu].l>=t){printf("%I64d %d\n",x-t,y);return 1;}
				else {start(uccu,t-(x-a[uccu].l));return 1;}
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&b);
	rep(i,1,n){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		a[i].mk(x1,y1,x2,y2);
		if(a[i].kind==0)sshu[a[i].pos].insert(pii(a[i].r,i));
		else hheng[a[i].pos].insert(pii(a[i].r,i));
	}
	shu.kind=0;
	shu.build();
	
	heng.kind=1;
	heng.build();
	scanf("%d",&q);
	gt.build();
	//rep(i,1,n)printf("for %d:%d %I64d\n",i,gt.go[0][i],gt.cost[0][i]);
	while(q--){
		int x,y;char opt[3];scanf("%d%d",&x,&y);scanf("%s",opt+1);LL t;scanf("%I64d",&t);
		if(tp_online(x,y,t))continue;
		LL use=0;set<pii>::iterator bg;int mudi,uccu;
		if(opt[1]=='L'){
			bg=hheng[y].lower_bound(pii(x,0));
			uccu=shu.before(y,x);
			if(bg==hheng[y].begin()&&uccu==-1){
				printf("%I64d %d\n",max(x-t,0ll),y);
				goto areend;
			}
			
			if(bg==hheng[y].begin()){
				if(x-a[uccu].pos>=t){printf("%I64d %d\n",x-t,y);goto areend;}
				t-=(x-a[uccu].pos);
				if(a[uccu].dir==1){if(a[uccu].r-y>=t){printf("%d %I64d\n",a[uccu].pos,y+t);goto areend;}
				else {start(uccu,t-(a[uccu].r-y));goto areend;}}
				if(a[uccu].dir==-1){if(y-a[uccu].l>=t){printf("%d %I64d\n",a[uccu].pos,y-t);goto areend;}
				else {start(uccu,t-(y-a[uccu].l));goto areend;}}
			}
			
			--bg;int node=(*bg).se;
			
			if(uccu==-1){
				if(x-a[node].r>=t){printf("%I64d %d\n",x-t,y);goto areend;}
				t-=(x-a[node].r);if(a[node].dir==1){start(node,t);goto areend;}
				if(a[node].r-a[node].l>=t){printf("%I64d %d\n",a[node].r-t,y);goto areend;}
				else {start(node,t-(a[node].r-a[node].l));goto areend;}
			}
			
			if(a[uccu].pos>a[node].r){
				if(x-a[uccu].pos>=t){printf("%I64d %d\n",x-t,y);goto areend;}
				t-=(x-a[uccu].pos);
				if(a[uccu].dir==1){if(a[uccu].r-y>=t){printf("%d %I64d\n",a[uccu].pos,y+t);goto areend;}
				else {start(uccu,t-(a[uccu].r-y));goto areend;}}
				if(a[uccu].dir==-1){if(y-a[uccu].l>=t){printf("%d %I64d\n",a[uccu].pos,y-t);goto areend;}
				else {start(uccu,t-(y-a[uccu].l));goto areend;}}
			}
			else{
				if(x-a[node].r>=t){printf("%I64d %d\n",x-t,y);goto areend;}
				t-=(x-a[node].r);if(a[node].dir==1){start(node,t);goto areend;}
				if(a[node].r-a[node].l>=t){printf("%I64d %d\n",a[node].r-t,y);goto areend;}
				else {start(node,t-(a[node].r-a[node].l));goto areend;}
			}
		}
		if(opt[1]=='R'){
			bg=hheng[y].lower_bound(pii(x,0));
			uccu=shu.after(y,x);
			if(bg==hheng[y].end()&&uccu==-1){printf("%I64d %d\n",min(x+t,b*1ll),y);goto areend;}
			
			if(bg==hheng[y].end()){
				if(a[uccu].pos-x>=t){printf("%I64d %d\n",x+t,y);goto areend;}
				t-=(a[uccu].pos-x);
				if(a[uccu].dir==1){if(a[uccu].r-y>=t){printf("%d %I64d\n",a[uccu].pos,y+t);goto areend;}
				else {start(uccu,t-(a[uccu].r-y));goto areend;}}
				if(a[uccu].dir==-1){if(y-a[uccu].l>=t){printf("%d %I64d\n",a[uccu].pos,y-t);goto areend;}
				else {start(uccu,t-(y-a[uccu].l));goto areend;}}
			}
			
			int node=(*bg).se;
			if(uccu==-1){
				if(a[node].l-x>=t){printf("%I64d %d\n",x+t,y);goto areend;}
				t-=(a[node].l-x);if(a[node].dir==-1){start(node,t);goto areend;}
				if(a[node].r-a[node].l>=t){printf("%I64d %d\n",a[node].l+t,y);goto areend;}
				else {start(node,t-(a[node].r-a[node].l));goto areend;}
			}
			
			if(a[uccu].pos<a[node].l){
				if(a[uccu].pos-x>=t){printf("%I64d %d\n",x+t,y);goto areend;}
				t-=(a[uccu].pos-x);
				if(a[uccu].dir==1){if(a[uccu].r-y>=t){printf("%d %I64d\n",a[uccu].pos,y+t);goto areend;}
				else {start(uccu,t-(a[uccu].r-y));goto areend;}}
				if(a[uccu].dir==-1){if(y-a[uccu].l>=t){printf("%d %I64d\n",a[uccu].pos,y-t);goto areend;}
				else {start(uccu,t-(y-a[uccu].l));goto areend;}}
			}
			else{
				if(a[node].l-x>=t){printf("%I64d %d\n",x+t,y);goto areend;}
				t-=(a[node].l-x);if(a[node].dir==-1){start(node,t);goto areend;}
				if(a[node].r-a[node].l>=t){printf("%I64d %d\n",a[node].l+t,y);goto areend;}
				else {start(node,t-(a[node].r-a[node].l));goto areend;}
			}
		}
		if(opt[1]=='U'){
			bg=sshu[x].lower_bound(pii(y,0));
			uccu=heng.after(x,y);
			if(bg==sshu[x].end()&&uccu==-1){printf("%d %I64d\n",x,min(y+t,b*1ll));goto areend;}
			
			if(bg==sshu[x].end()){
				if(a[uccu].pos-y>=t){printf("%d %I64d\n",x,y+t);goto areend;}
				t-=(a[uccu].pos-y);
				if(a[uccu].dir==1){if(a[uccu].r-x>=t){printf("%I64d %d\n",x+t,a[uccu].pos);goto areend;}
				else {start(uccu,t-(a[uccu].r-x));goto areend;}}
				if(a[uccu].dir==-1){if(x-a[uccu].l>=t){printf("%I64d %d\n",x-t,a[uccu].pos);goto areend;}
				else {start(uccu,t-(x-a[uccu].l));goto areend;}}
			}
			
			int node=(*bg).se;
			
			if(uccu==-1){
				if(a[node].l-y>=t){printf("%d %I64d\n",x,y+t);goto areend;}
				t-=(a[node].l-y);
				if(a[node].dir==-1){start(node,t);goto areend;}
				if(a[node].r-a[node].l>=t){printf("%d %I64d\n",x,a[node].l+t);goto areend;}
				else {start(node,t-(a[node].r-a[node].l));goto areend;}
			}
			
			if(a[uccu].pos<a[node].l){
				if(a[uccu].pos-y>=t){printf("%d %I64d\n",x,y+t);goto areend;}
				t-=(a[uccu].pos-y);
				if(a[uccu].dir==1){if(a[uccu].r-x>=t){printf("%I64d %d\n",x+t,a[uccu].pos);goto areend;}
				else {start(uccu,t-(a[uccu].r-x));goto areend;}}
				if(a[uccu].dir==-1){if(x-a[uccu].l>=t){printf("%I64d %d\n",x-t,a[uccu].pos);goto areend;}
				else {start(uccu,t-(x-a[uccu].l));goto areend;}}
			}
			else{
				if(a[node].l-y>=t){printf("%d %I64d\n",x,y+t);goto areend;}
				t-=(a[node].l-y);
				if(a[node].dir==-1){start(node,t);goto areend;}
				if(a[node].r-a[node].l>=t){printf("%d %I64d\n",x,a[node].l+t);goto areend;}
				else {start(node,t-(a[node].r-a[node].l));goto areend;}
			}
		}
		if(opt[1]=='D'){
			bg=sshu[x].lower_bound(pii(y,0));
			uccu=heng.before(x,y);
			if(bg==sshu[x].begin()&&uccu==-1){printf("%d %I64d\n",x,max(0ll,y-t));goto areend;}
			
			if(bg==sshu[x].begin()){
				if(y-a[uccu].pos>=t){printf("%d %I64d\n",x,y-t);goto areend;}
				t-=(y-a[uccu].pos);
				if(a[uccu].dir==1){if(a[uccu].r-x>=t){printf("%I64d %d\n",x+t,a[uccu].pos);goto areend;}
				else {start(uccu,t-(a[uccu].r-x));goto areend;}}
				if(a[uccu].dir==-1){if(x-a[uccu].l>=t){printf("%I64d %d\n",x-t,a[uccu].pos);goto areend;}
				else {start(uccu,t-(x-a[uccu].l));goto areend;}}
			}
			--bg;
			int node=(*bg).se;
			
			if(uccu==-1){
				if(y-a[node].r>=t){printf("%d %I64d\n",x,y-t);goto areend;}
				t-=(y-a[node].r);
				if(a[node].dir==1){start(node,t);goto areend;}
				if(a[node].r-a[node].l>=t){printf("%d %I64d\n",x,a[node].r-t);goto areend;}
				else {start(node,t-(a[node].r-a[node].l));goto areend;}
			}
			
			if(a[uccu].pos>a[node].r){
				if(y-a[uccu].pos>=t){printf("%d %I64d\n",x,y-t);goto areend;}
				t-=(y-a[uccu].pos);
				if(a[uccu].dir==1){if(a[uccu].r-x>=t){printf("%I64d %d\n",x+t,a[uccu].pos);goto areend;}
				else {start(uccu,t-(a[uccu].r-x));goto areend;}}
				if(a[uccu].dir==-1){if(x-a[uccu].l>=t){printf("%I64d %d\n",x-t,a[uccu].pos);goto areend;}
				else {start(uccu,t-(x-a[uccu].l));goto areend;}}
			}
			else{
				if(y-a[node].r>=t){printf("%d %I64d\n",x,y-t);goto areend;}
				t-=(y-a[node].r);
				if(a[node].dir==1){start(node,t);goto areend;}
				if(a[node].r-a[node].l>=t){printf("%d %I64d\n",x,a[node].r-t);goto areend;}
				else {start(node,t-(a[node].r-a[node].l));goto areend;}
			}
		}
		areend:;
	}	
	//rep(i,1,n)printf("for %d:%d %I64d\n",i,gt.go[0][i],gt.cost[0][i]);
	return 0;
}