#include<bits/stdc++.h>
using namespace std;
#define MN 1000005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline bool chkmax(int &a,int b){if(a<b)return a=b,1;return 0;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
struct data{
	int u,v,l,r,t;
	data(int U=0,int V=0,int L=0,int R=0,int T=0){
		u=U;v=V;l=L;r=R;t=T;
	}	
	bool friend operator<(data a,data b){
		return a.l>b.l;
	}
};
priority_queue<data>EDG;
vector<data>edge[MN][2];
int n,m,f[MN][2];
void solve(int u,int v,int l,int r){
	bool op=l&1;
	if(f[u][op]>=l){
		if(v==n){printf("%d\n",l+1);exit(0);}
		if(chkmax(f[v][!op],r+1)){
			for(int i=0;i<edge[v][!op].size();++i){
				data tmp=edge[v][!op][i];
				EDG.push(data(tmp.u,tmp.v,l+1,tmp.r));
			}
			edge[v][!op].clear();
		}
	}
	else edge[u][op].push_back(data(u,v,l,r));
}
int main(){
	n=read();m=read();
	if(n==1){puts("0");return 0;}
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),l=read(),r=read()-1;
		int op=(r-l)&1;
		EDG.push(data(u,v,l,r-op,1));
		EDG.push(data(u,v,l+1,r-(!op),1));
	}
	memset(f,-0x3f,sizeof(f));f[1][0]=0;
	while(!EDG.empty()){
		data w=EDG.top();EDG.pop();
		if(w.l>w.r)continue;
		solve(w.u,w.v,w.l,w.r);
		if(w.t==1)solve(w.v,w.u,w.l,w.r);
	}
	puts("-1");
	return 0;
}