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
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int MOD=998244353;
const int SQRT=400;
int n,a[MAXN+5];
int dp[2][SQRT*2+5],cnt[2][SQRT*2+5];
int id[MAXN+5],idcnt,pos[SQRT*2+5];
int _id[MAXN+5],_idcnt,_pos[SQRT*2+5];
void getid(int v,int *id,int &idcnt,int *pos){
	idcnt=0;
	for(int l=1,r;l<=v;l=r+1){
		r=(v/(v/l));
		id[v/l]=++idcnt;
		pos[idcnt]=v/l;
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	fill0(dp[0]);fill0(dp[1]);fill0(cnt[0]);fill0(cnt[1]);
	int cur=1,pre=0,res=0;
	for(int i=n;i;i--){
		fill0(dp[cur]);fill0(cnt[cur]);
		getid(a[i],id,idcnt,pos);cnt[cur][id[a[i]]]++;
		if(i!=n){
			getid(a[i+1],_id,_idcnt,_pos);
			for(int j=1;j<=_idcnt;j++){ 
				int v=_pos[j],stp=(a[i]-1)/v,to=a[i]/(stp+1);
				cnt[cur][id[to]]+=cnt[pre][j];
				dp[cur][id[to]]=(0ll+dp[cur][id[to]]+1ll*stp*cnt[pre][j]+dp[pre][j])%MOD;
			}
			for(int j=1;j<=idcnt;j++) res=(res+dp[cur][j])%MOD;
		}
		swap(cur,pre);
	} printf("%d\n",res);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}