#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<unordered_map>
#include<queue>
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
int n,m,k;
int ec,er,hc,hr;
int pw[1000010];
int cnt[2];
int c[1000010][2],r[1000010][2];
const int mod=998244353;
map<PII,int>Map;
void del(int x,int y,int w){
	--cnt[(x^y^w)&1];
	if(!--c[x][(y^w)&1]){
		if(!c[x][((y^w)&1)^1]) --hr,++er;
		else ++hr;
	}
	if(!--r[y][(x^w)&1]){
		if(!r[y][(x^w^1)&1]) --hc,++ec;
		else ++hc;
	}
}
void ins(int x,int y,int w){
	if(w==-1) return ;
	++cnt[(x^y^w)&1];
	if(!c[x][(y^w)&1]){
		if(!c[x][(y^w^1)&1]) --er,++hr;
		else --hr;
	}c[x][(y^w)&1]++;
	if(!r[y][(x^w)&1]){
		if(!r[y][(x^w^1)&1]) --ec,++hc;
		else --hc;
	}r[y][(x^w)&1]++;
	// printf("%d %d %d,%d %d,%d %d\n",x,y,w,er,hr,ec,hc);
}
int main(){
	n=read(),m=read(),k=read();ec=m,er=n;
	pw[0]=1;for(int i=1;i<=1000000;++i) pw[i]=(pw[i-1]+pw[i-1])%mod;
	while(k--){
		int x=read(),y=read(),w=read();
		if(!Map.count(mp(x,y))) Map[mp(x,y)]=-1;
		if(Map[mp(x,y)]!=-1){
			del(x,y,Map[mp(x,y)]);Map[mp(x,y)]=-1;
		}
		int ans=0;
		ins(x,y,w);Map[mp(x,y)]=w;
		// printf("%d %d %d %d\n",ec,hc,er,hr);
		if(ec+hc==m) (ans+=pw[ec])%=mod;
		if(er+hr==n) (ans+=pw[er])%=mod;
		ans-=(!cnt[0]);ans-=(!cnt[1]);
		printf("%d\n",(ans+mod)%mod);
	}
}