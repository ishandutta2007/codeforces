#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls k<<1
#define rs k<<1|1
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define nowtime ((ll)clock()*1000/CLOCKS_PER_SEC)
#define fore(i,x,y) for(int i=head[(x)];i!=(y);i=p[i].next)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define REP(i,x,y) for(int i=(x);i<(y);i++)
#define PER(i,x,y) for(int i=(x);i>(y);i--)
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=1000005,mod=1e9+7;
int n,m,k;
struct sgt{
	int flag[N<<3];
	bool same[N<<3];
	inline void clear(){
		memset(flag,0,sizeof(flag));
		memset(same,0,sizeof(same));
	}
	inline void upt(const int k){flag[k]=0;same[k]=1;}
	inline void upt(const int k,const int b){flag[k]+=b;if(flag[k]>=mod) flag[k]-=mod;}
	inline void pushdown(const int k){
		if(same[k]) upt(ls),upt(rs),same[k]=0;
		if(flag[k]) upt(ls,flag[k]),upt(rs,flag[k]),flag[k]=0;
	}
	inline void change(const int l,const int r,const int x,const int y,const int k){
		if(l==x&&y==r){upt(k);return;}
		pushdown(k);
		int mid=l+r>>1;
		if(x<=mid) change(l,mid,x,min(y,mid),ls);
		if(y>mid) change(mid+1,r,max(mid+1,x),y,rs);
	}
	inline void change(const int x,const int y){change(1,m,x,y,1);}
	inline void add(const int l,const int r,const int x,const int y,const int k,const int b){
		if(l==x&&y==r){upt(k,b);return;}
		pushdown(k);
		int mid=l+r>>1;
		if(x<=mid) add(l,mid,x,min(y,mid),ls,b);
		if(y>mid) add(mid+1,r,max(mid+1,x),y,rs,b);
	}
	inline void add(const int x,const int y,const int b){
		if(x>y) return;
		add(1,m,x,y,1,b);
	}
	inline int get(const int l,const int r,const int x,const int k){
		if(l==r)return flag[k];
		pushdown(k);
		int mid=l+r>>1;
		if(x<=mid) return get(l,mid,x,ls);
		return get(mid+1,r,x,rs);
	}
	inline int get(const int x){if(!x) return 0;return get(1,m,x,1);}
}p;
vector<pii> rd[N];
vi cd[N];
set<int> s;
set<int>::iterator it;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		rd[a].pb(mp(b,d));
		cd[c+1].pb(b);
	}
	p.clear();
	rep(i,1,n){
		sort(rd[i].begin(),rd[i].end());
		sort(cd[i].begin(),cd[i].end());
	}
	if(rd[1].size()) p.add(1,rd[1][0].FF-1,1); else p.add(1,m,1);
	rep(i,1,n){
		reverse(rd[i].begin(),rd[i].end());
		reverse(cd[i].begin(),cd[i].end());
	}
	REP(i,0,rd[1].size()) s.insert(rd[1][i].FF);
	int clo=0;
	rep(i,2,n){
		REP(j,0,cd[i].size()) s.erase(s.find(cd[i][j]));
		REP(j,0,rd[i].size()){
			int l=rd[i][j].FF,r=rd[i][j].SS;
			p.change(l,r);
			clo-=nowtime;
			s.insert(l);clo+=nowtime;
		}
		REP(j,0,cd[i].size()){
			int l=cd[i][j],r;
			it=s.lower_bound(l);
			if(it!=s.end()) r=(*it)-1; else r=m;
			p.add(l,r,p.get(l-1));
		}
	}
	printf("%d\n",p.get(m));
	return 0;
}