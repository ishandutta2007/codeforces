#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T> void read(T &x){
	x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
}
const int MAXN=1e5;
const int LOG_N=17;
int n,qu,a[MAXN+5],nxt[MAXN+5][LOG_N+2];
vector<int> fac[MAXN+5];
bool book[MAXN+5];
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int tmp=a[i];
		for(int j=2;j*j<=tmp;j++){
			if(tmp%j==0){
				fac[i].pb(j);
				while(tmp%j==0) tmp/=j;
			}
		} if(tmp>1) fac[i].pb(tmp);
	}
	for(int i=1,j=1;i<=n;i++){
		while(j<=n){
			bool flg=1;
			for(int u:fac[j]) if(book[u]) flg=0;
			if(!flg) break;
			for(int u:fac[j]) book[u]=1;j++;
		} nxt[i][0]=j;//printf("%d %d\n",i,j);
		for(int u:fac[i]) book[u]=0;
	} nxt[n+1][0]=n+1;
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n+1;j++)
		nxt[j][i]=nxt[nxt[j][i-1]][i-1];
	while(qu--){
		int l,r,ans=0;scanf("%d%d",&l,&r);
		for(int i=LOG_N;~i;i--) if(nxt[l][i]<=r) l=nxt[l][i],ans|=(1<<i);
		printf("%d\n",ans+1);
	}
	return 0;
}