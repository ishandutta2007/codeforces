#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<bitset>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
int a[100010][6],c[100010][6];
int b[500010];
PII w[100010];
int Cnt;
struct state{
	int cnt;
	unordered_map<int,int>tr;
	int trans(int x){
		if(tr.count(x)) return tr[x];
		else return tr[x]=++Cnt;
	}
}sta[3200010];
void upd(int p,int x,int i,int k){
	// printf("p:%d,x:%d,i:%d,k:%d\n",p,x,i,k);
	if(i==m+1){
		sta[p].cnt+=k;return ;
	}
	upd(p,x,i+1,k);
	upd(sta[p].trans(c[x][i]),x,i+1,k);
}
void add(int x,int k){
	upd(0,x,1,k);
}
int dfs(int p,int x,int i){
	// printf("p:%d,x:%d,i:%d\n",p,x,i);
	if(i==m+1) return sta[p].cnt;
	int ret=dfs(p,x,i+1);
	if(sta[p].tr.count(c[x][i])) ret-=dfs(sta[p].trans(c[x][i]),x,i+1);
	return ret;
}
int getcnt(int x){
	return dfs(0,x,1);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
		    a[i][j]=read();b[(i-1)*m+j]=a[i][j];
	    }
		w[i]=mp(read(),i);
	}
	sort(w+1,w+n+1);
	sort(b+1,b+n*m+1);
	int M=unique(b+1,b+n*m+1)-b-1;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
		a[i][j]=lower_bound(b+1,b+M+1,a[i][j])-b;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			c[i][j]=a[w[i].se][j];
		}
		sort(c[i]+1,c[i]+m+1);
	}
	int L,R=1;
	while(R<=n&&getcnt(R)==0){
		add(R,1);++R;
	}
	// printf("R:%d\n",R);
	if(R>n){
		printf("-1\n");return 0;
	}
	L=R-1;add(L,-1);
	while(L>1&&getcnt(R)!=0){
		--L;add(L,-1);
	}
	// printf("L:%d\n",L);
	int ans=w[L].fi+w[R].fi;
	++R;
	for(;R<=n;++R){
		while(L>1&&getcnt(R)!=0){
			--L;add(L,-1);
		}
		ans=min(ans,w[R].fi+w[L].fi);
	}
	printf("%d\n",ans);
}