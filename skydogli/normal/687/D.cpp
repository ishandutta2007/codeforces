#include<bits/stdc++.h>
using namespace std;
#define MN 500005
#define mn 1005
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
#define pvi pair<vector<data>,int>
#define mp make_pair
#define x first
#define y second
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
int n,m,q;
struct data{
	int x,y,z,id;
	bool friend operator<(data a,data b){
		return a.z>b.z;
	}
}w[MN];
int F[mn<<1];
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
void con(int a,int b){
	F[Find(a)]=Find(b);
}
pvi e[MN<<2];
bool cmp(int a,int b){return w[a].z>w[b].z;}
void init(int x){F[x]=x;F[x+n]=x+n;}
pvi Merge(const pvi &a,const pvi &b){
	vector<data>p;p.clear();
	p.resize(a.x.size()+b.x.size());
	merge(a.x.begin(),a.x.end(),b.x.begin(),b.x.end(),p.begin());
//	int p1=0,p2=0;
	if(p.size()>=n/2)for(int i=1;i<=(n<<1);++i)F[i]=i;
	else for(int i=0;i<p.size();++i){
		init(p[i].x);init(p[i].y);
	}
	pvi fin;
	int cnt=0;
	fin.x.resize(a.x.size()+b.x.size());
	fin.y=-1;
	for(int i=0;i<p.size();++i){
		int x=p[i].x,y=p[i].y;	
		if(Find(x)==Find(y)){
			fin.y=p[i].z;
			fin.x[cnt++]=(p[i]);
			break;
		}
		else{
			if(Find(x)!=Find(y+n)||Find(x+n)!=Find(y)){
				con(x,y+n);
				con(x+n,y);
				fin.x[cnt++]=(p[i]);
				if(Find(x)==Find(x+n)||Find(y)==Find(y+n)){
					fin.y=p[i].z;
					break;
				}
			}
		}
	}
	fin.x.resize(cnt);
	return fin;
}
void build(int x,int l,int r){
	if(l==r){e[x].x.push_back(w[l]);e[x].y=-1;return;}
	build(Ls,l,mid);
	build(Rs,mid+1,r);
	e[x]=Merge(e[Ls],e[Rs]);
}

pvi ask(int x,int l,int r,int b,int _e){
	if(b<=l&&r<=_e){
		return e[x];	
	}
	if(b>mid)return ask(Rs,mid+1,r,b,_e);
	if(_e<=mid)return ask(Ls,l,mid,b,_e);
	return Merge(ask(Ls,l,mid,b,_e),ask(Rs,mid+1,r,b,_e));
}

int main(){
//	freopen("CF687D.in","r",stdin);
//	freopen("CF687D.out","w",stdout);
	n=read();m=read();q=read();
	for(int i=1;i<=m;++i){
		w[i].x=read();w[i].y=read();w[i].z=read();
	}
	build(1,1,m);
	w[0].z=-1;
	while(q--){
		int l=read(),r=read();
		printf("%d\n",ask(1,1,m,l,r).y);
	}
	return 0;
}