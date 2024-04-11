#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 400005
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
int fa[MN],ch[MN][2],tag[MN],siz[MN],li[MN];
pii mx[MN],val[MN];
int getpos(int x){return ch[fa[x]][1]==x;}
bool isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
void pushup(int x){
	assert(li[x]>=0);
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+li[x];
	mx[x]=max(max(mx[ch[x][0]],mx[ch[x][1]]),val[x]);
}
void ptag(int x){swap(ch[x][0],ch[x][1]);tag[x]^=1;}
void pd(int x){if(tag[x]){ptag(ch[x][0]);ptag(ch[x][1]);tag[x]=0;}}
void rotate(int x){
	int y=fa[x],z=fa[y],d=getpos(x);
	ch[y][d]=ch[x][!d];if(ch[x][!d])fa[ch[x][!d]]=y;
	fa[x]=z;if(!isroot(y)) ch[z][getpos(y)]=x;	
	fa[y]=x;ch[x][!d]=y;
	pushup(y);
	pushup(x);
}
int st[MN],top;
void splay(int x){
	int tmp=x;st[top=1]=x;
	while(!isroot(x)){x=fa[x];st[++top]=x;}
	while(top)pd(st[top--]);
	x=tmp;
	while(!isroot(x)){
		int y=fa[x],z=fa[y];
		if(!isroot(y)){
			rotate(getpos(x)==getpos(y)?y:x);
		}
		rotate(x);
	}
}
void access(int x){
	for(int y=0;x;x=fa[y=x]){

		splay(x);
//		cerr<<"? "<<x<<" "<<y<<": "<<li[x]<<" "<<siz[y]<<" "<<siz[ch[x][1]]<<endl;
		li[x]-=siz[y];
		li[x]+=siz[ch[x][1]];
		ch[x][1]=y;
		pushup(x);
//		cerr<<"access: "<<x<<" "<<ch[x][0]<<" "<<ch[x][1]<<": "<<li[x]<<" "<<siz[x]<<" "<<endl;
//		cerr<<"? "<<x<<" "<<y<<": "<<li[x]<<" ch: "<<ch[x][0]<<" "<<siz[ch[x][0]]<<" siz: "<<siz[x]<<endl;
		assert(siz[x]>=0);
	}
//	cerr<<"done"<<endl;
}
void makeroot(int x){
	access(x);
	splay(x);ptag(x);access(x);
}
int n,m,F[MN],op[MN];
void link(int x,int y){
//	cerr<<"link: "<<x<<" "<<y<<endl;
	makeroot(x);
	//access(y);
	//splay(y);
	makeroot(y);
	fa[x]=y;
	li[y]+=siz[x];
	pushup(y);
	assert(siz[y]>=0);
//	cerr<<"linked"<<endl;
}
void cut(int x,int y){
//	cerr<<"cut: "<<x<<" "<<y<<endl;
	makeroot(x);
	access(y);
	splay(y);
	fa[x]=ch[y][0]=0;
	pushup(y);
	assert(siz[y]>=0);
}
int u[MN],v[MN],w[MN];
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
set<pii >S;
void maintain(){
	while(S.size()){
		pii e=*(--S.end());
		int x=u[e.y],y=e.y;
		makeroot(x);
		access(y);splay(y);
		assert(siz[x]);
		if(siz[x]%2==0){
			S.erase(e);
		}
		else break;
	}
}
int main(){
	n=read();m=read();
	if(n&1){
		while(m--)puts("-1");
		return 0;
	}
	for(int i=1;i<=n;++i)F[i]=i,op[i]=1;
	for(int i=1;i<=n;++i)siz[i]=li[i]=1;
	int cnt=n;
	for(int i=n+1;i<=n+m;++i){
		u[i]=read(),v[i]=read(),w[i]=read();
		val[i]=mp(w[i],i);
		int fu=Find(u[i]),fv=Find(v[i]);
		if(fu!=fv){
			if(op[fu]&&op[fv])cnt-=2;
			op[fu]^=op[fv];
			F[fv]=fu;
			link(u[i],i);
			link(i,v[i]);
			S.insert(mp(w[i],i));
		}
		else{
			int x=u[i],y=v[i];
			makeroot(x);
			access(y);
			splay(y);
			pii e=mx[y];	
			if(e.x>w[i]){
				cut(u[e.y],e.y);
				cut(v[e.y],e.y);
				if(S.find(mp(e.x,e.y))!=S.end()){
					S.erase(mp(e.x,e.y));
				}
				link(x,i);
				link(y,i);
				S.insert(mp(w[i],i));
			}
		}
		if(cnt){
			puts("-1");
		}
		else{ 
			maintain();
			printf("%d\n",(*(--S.end())).x);
		}
	}
	return 0;
}