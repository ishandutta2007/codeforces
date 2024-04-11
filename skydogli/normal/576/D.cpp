#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define mn 155
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
#define piii pair<int,pii >
int n,m;
piii a[mn];
struct mat{
	bitset<mn>a[mn];
	void init(){for(int i=1;i<=n;++i)a[i].reset();}
}f,g;
mat operator *(mat a,mat b){
	mat c;c.init();
	for(int i=1;i<=n;++i) for ( int k = 1; k <= n; ++ k ) 
		if ( a.a[i][k] ) 
			c.a[i] |= b.a[k];
	return c;
}
void MUL(int k){
	mat w=g;
	while(k){
		if(k&1)f=f*w;
		w=w*w;
		k>>=1;
	}
}
queue<int >q;
int F[mn];
void bfs(){
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=1;i<=n;++i)
			if(F[i]>F[x]+1&&g.a[x][i]){
				F[i]=F[x]+1;
				q.push(i);
			}
	}
}
signed main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		a[i].y.x=read(),a[i].y.y=read();a[i].x=read();
	}	
	sort(a+1,a+1+m);
	f.a[1][1]=1;
	int t=0;
	for(int i=1;i<=m;++i){
		if(t!=a[i].x){
			while(!q.empty())q.pop();
			for(int i=1;i<=n;++i)F[i]=1e9;
			for(int i=1;i<=n;++i)if(f.a[1][i])q.push(i),F[i]=0;
			MUL(a[i].x-t);
			if(f.a[1][n]){
				bfs();
				printf("%d\n",t+F[n]);	
				return 0;
			}
			t=a[i].x;
		}
		g.a[a[i].y.x][a[i].y.y]=1;
//		cerr<<"ad: "<<a[i].y.x<<" "<<a[i].y.y<<" "<<f.a[1][2]<<endl;
	}
	while(!q.empty())q.pop();
	for(int i=1;i<=n;++i)F[i]=1e9;
	for(int i=1;i<=n;++i)if(f.a[1][i])q.push(i),F[i]=0;
	bfs();
	if(F[n]>1e8)puts("Impossible");
	else printf("%d\n",F[n]+t);
	return 0;
}