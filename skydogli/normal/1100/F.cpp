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
#define MN 500005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int T,n,m;
int a[MN],upbit[MN];
bool vis[25];
int pos[25],cnt,v[25];
int ans[MN];
vector<pii >q[MN];
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	m=read();
	for(int i=1;i<=m;++i){
		int l=read(),r=read();
		q[r].push_back(mp(l,i));
	}	
	for(int i=1;i<=n;++i){	
		int x=i,V=a[i];
		for(int j=19;j>=0;--j){
			if((V>>j)&1){
				if(!pos[j]){
					v[j]=V;pos[j]=x;
					break;
				}
				if(pos[j]>x){V^=v[j];continue;}
				int vv=V^v[j];
				v[j]=V;
				swap(pos[j],x);
				V=vv;
			}
		}
		for(int j=0;j<q[i].size();++j){
			int res=0;
			for(int k=19;k>=0;--k)
				if(pos[k]>=q[i][j].x){
					if((res^v[k])>res)res^=v[k];
				}
			ans[q[i][j].y]=res;
		}
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}