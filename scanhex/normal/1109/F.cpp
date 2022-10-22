#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
const int N=1<<18;
#define le(x) ch[x][0]
#define ri(x) ch[x][1]
int fa[N],sz[N];
int flag[N];
int ch[N][2];
int chnum(int x){
	return ri(fa[x])==x;
}
int is_r(int x){
	return !(ri(fa[x])==x||le(fa[x])==x);
}
void push(int x){
	if(flag[x]){
		swap(le(x),ri(x));
		flag[le(x)]^=1,flag[ri(x)]^=1;
		flag[x]=0;
	}
}
void rev(int x){
	flag[x]=true;
	push(x);
}
void update(int x){
	if(x)sz[x]=1+sz[le(x)]+sz[ri(x)];
}
void attach(int x,int y,int side){
	fa[x]=y;
	ch[y][side]=x;
}
void check(int x){
	assert(sz[x]==sz[le(x)]+sz[ri(x)]+1);
}
void rotate(int x){
	int y=fa[x],z=fa[y],b=chnum(x),t=ch[x][b^1];
	int c=chnum(fa[x]);
	if(!is_r(y))
		attach(x,z,c);
	else
		fa[x]=z;
	attach(y,x,b^1);
	attach(t,y,b);
	update(y);
	update(x);
}
void splay(int x){
	static int mem[N];
	static int ptr=0;
	int y=x;
	while(!is_r(y))mem[ptr++]=y,y=fa[y];
	mem[ptr++]=y;
	while(ptr>0)push(mem[ptr-1]),--ptr;
	while(!is_r(x)){
		int y=fa[x];
		if(!is_r(fa[x]))
			rotate(chnum(x)==chnum(y)?y:x);
		rotate(x);
	}
}

void print(int x){
	if(!x)return;
	check(x);
	print(le(x));
	cerr<<x<<' ';
	print(ri(x));
}

void access(int x){
    for(int dwn=0;x;dwn=x,x=fa[x]) splay(x),ri(x)=dwn,update(x);
	/*
	splay(x);
	ri(x)=0;
	while(fa[x]){
		splay(x);
		if(fa[x])
			ri(fa[x])=x,update(fa[x]);
	}
	*/
}
void makeroot(int x){
	access(x),splay(x),rev(x);
}
bool is_conn(int x,int y){
	if(x==y)return 1;
	makeroot(x);
	makeroot(y);
	return !(fa[x]==0&&fa[y]==0);
}
void cut(int x,int y){
	makeroot(x);
	access(y);
	splay(y);
	assert(le(y)==x);
	le(y)=fa[x]=0;
	update(y);
}
void link(int x,int y){
	makeroot(x);
	makeroot(y);
	assert(fa[x]==0);
	fa[x]=y;
}
int n,m;

const int S=1010;
int matr[S][S];

int nocyc[N];

int kek(pair<int,int>mem){
	 return mem.first*m+mem.second+1;
}
vector<int>dx={0,1,0,-1},dy={1,0,-1,0};

bool added[N];

vector<int>neigh(int a){
	--a;
	int x=a/m,y=a%m;
	vector<int>ans;
	for(int i=0;i<4;++i){
		 int x1=x+dx[i],y1=y+dy[i];
		 if(x1>=0&&y1>=0&&x1<n&&y1<m&&added[x1*m+y1+1])
			 ans.push_back(x1*m+y1+1);
	}
	return ans;
}

bool check(pair<int,int>a){
	int x=kek(a);
	auto ne=neigh(x);
	for(int i=0;i<ne.size();++i)
		for(int j=0;j<i;++j)
			if(is_conn(ne[i],ne[j]))
				return false;
	return true;
}
void add(pair<int,int>a){
	 int x=kek(a);
	 added[x]=true;
	 for(int y:neigh(x)){
		 assert(!is_conn(x,y));
		 link(x,y);
	 }
}
void rem(pair<int,int>a){
	 int x=kek(a);
	 added[x]=false;
	 for(int y:neigh(x)){
		 assert(is_conn(x,y));
		 cut(x,y);
	 }
}

const int oo=1e9;

int C=1;

struct it{
	int sum[2*N],mn[2*N],mn1[2*N],cntmn[2*N],cntmn1[2*N];
	it(){
		for(int i=2*N-1;i>=0;--i){
			if(i<n)
				update(i);
			else
				sum[i]=0,mn[i]=0,cntmn[i]=1,cntmn1[i]=0;
		}
	}
	void update(int i){
		int le=2*i;
		int ri=2*i+1;
		sum[i]=sum[le]+sum[ri];
		mn[i]=min(mn[2*i],sum[le]+mn[2*i+1]);
		cntmn[i]=0;
		if(mn[le]==mn[i])cntmn[i]+=cntmn[le];
		if(sum[le]+mn[ri]==mn[i])cntmn[i]+=cntmn[ri];
	}
	void add(int i,int ch){
		i+=N;
		sum[i]+=ch;
		mn[i]=sum[i];
		cntmn[i]=1;
		while(i>1)
			update(i>>1),i>>=1;
	}
	int get(int x,int l,int r,int ql,int qr,int cur){
		if(cur+mn[x]>C)return 0;
		if(l>=qr||ql>=r)return 0;
		if(ql<=l&&r<=qr)
			if(cur+mn[x]==C)
				return cntmn[x];
			else{
				return 0;
			}
		int m=(l+r)/2;
		return get(x*2,l,m,ql,qr,cur)+get(x*2+1,m,r,ql,qr,cur+sum[x*2]);
	}
} myit;
mt19937 rnd(228);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	n=1000,m=200;
	cin>>n>>m;
	vector<int>kekos(n*m);
	iota(kekos.begin(),kekos.end(),1);
	shuffle(kekos.begin(),kekos.end(),rnd);
	for(int i=0;i<n*m;++i)
		sz[i]=1;
	int t=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			matr[i][j]=kekos[t++];
			cin>>matr[i][j];
			--matr[i][j];
		}
	vector<pair<int,int>>ord;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)ord.emplace_back(i,j);
	sort(ord.begin(),ord.end(),[&](pair<int,int> a,pair<int,int> b){
			return matr[a.first][a.second]<matr[b.first][b.second];
			});
	int cur=ord.size();
	for(int i=ord.size()-1;i>=0;--i){
		while(!check(ord[i]))rem(ord[--cur]);
		nocyc[i]=cur;
		add(ord[i]);
	}
	memset(added,0,sizeof added);
	nagai ansich=0;
	for(int i=ord.size()-1;i>=0;--i){
		int x=ord[i].first,y=ord[i].second;
		myit.add(i,1);
		for(int k=0;k<4;++k){
			 int x1=x+dx[k],y1=y+dy[k];
			 if(x1>=0&&y1>=0&&x1<n&&y1<m&&added[matr[x1][y1]])
				 myit.add(matr[x1][y1],-1);
		}
		added[i]=true;
		int mem=myit.get(1,0,N,i,nocyc[i],0);
		ansich+=mem;
	}
	cout<<ansich<<'\n';
}