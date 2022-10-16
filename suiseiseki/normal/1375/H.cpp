#include <cstdio>
#include <algorithm>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()){
		if(ch=='-'){
			f=-1;
		}
	}
	for(;isdigit(ch);ch=getchar()){
		x=x*10+ch-48;
	}
	return x*f;
}
const int mxN=1<<12;
const int mxM=1<<16;
const int mxSIZ=2.2e6;
const int mxB=1<<8;
int a[mxN+3],ai[mxN+3];
int n,m,siz,B;
int ans[mxM+3];
vector<pair<int,int> > way;
int merge(int u,int v){
	if(!u||!v){
		return u+v;
	}
	way.push_back(make_pair(u,v));
	return ++siz;
}
int f[mxB*2+3][mxB+3][mxB+3];
struct Block{
	int len,al,ar;
	int p[mxN+3];
	void solve(int u,int l,int r,vector<int> vec){
		if(l==r){
			f[u][1][1]=ai[vec[1]];
			return;
		}
		int mid=(l+r)>>1;
		vector<int> vecl(1),vecr(1);
		for(int i=1;i<(int)vec.size();i++){
			if(vec[i]<=mid){
				vecl.push_back(vec[i]);
			}
			else{
				vecr.push_back(vec[i]);
			}
		}
		solve(u<<1,l,mid,vecl);
		solve(u<<1|1,mid+1,r,vecr);
		for(int i=1,xl=1,xr=1;i<(int)vec.size();xl+=(vec[i]<=mid),xr+=(vec[i]>mid),i++){
			for(int j=i-1,yl=xl-1,yr=xr-1;j<vec.size();j++,yl+=(vec[j]<=mid),yr+=(vec[j]>mid)){
				if(j==i-1){
					continue;
				}
				f[u][i][j]=merge(f[u<<1][xl][yl],f[u<<1|1][xr][yr]);
			}
		}
	}
	int id[mxN+3],qwq[mxB+3][mxB+3];
	void build(){
		vector<int> vec(1);
		for(int i=1;i<=n;i++){
			if(a[i]>=al&&a[i]<=ar){
				vec.push_back(a[i]);
				id[i]=id[i-1]+1;
			}
			else{
				id[i]=id[i-1];
			}
		}
		solve(1,al,ar,vec);
		for(int i=1;i<(int)vec.size();i++){
			for(int j=1;j<(int)vec.size();j++){
				qwq[i][j]=f[1][i][j];
			}
		}
	}
	int query(int l,int r){
		return qwq[id[l-1]+1][id[r]];
	}
}blo[18];
int main(){
	n=read();
	m=read();
	siz=n;
	B=min(n,mxB);
	for(int i=1;i<=n;i++){
		a[i]=read();
		ai[a[i]]=i;
		siz=n;
	}
	for(int i=1;(i-1)*B+1<=n;i++){
		blo[i].al=(i-1)*B+1,blo[i].ar=i*B;
		blo[i].build();
	}
	for(int q=1;q<=m;q++){
		int l=read(),r=read();
		ans[q]=0;
		for(int i=1;i<=(n-1)/B+1;i++){
			ans[q]=merge(ans[q],blo[i].query(l,r));
		}
	}
	printf("%d\n",siz);
	for(int i=0;i<(int)way.size();i++){
		printf("%d %d\n",way[i].first,way[i].second);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}