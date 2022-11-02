#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define NN 210
#define MM 510
#define KK 22
int m,n,p;
int a[NN];
void add(int &u,int v){
	u+=v;
	if(u>=mod) u-=mod;
}
struct NUM{
	int len;
	int v[NN];
	void input(){
		scanf("%d",&len);
		for(int i=0;i<len;i++) scanf("%d",&v[i]);
	}
}L,R;
int dp[NN][NN][MM];
int q[NN];
int qb,qf,used;
struct node{
	int nxt[KK],fail,cnt;
	void clear(){
		memset(nxt,-1,sizeof nxt);
		fail=-1;
		cnt=0;
	}
}mem[NN];

struct AC_automation{
	int newnode(){
		int ans=++used;
		mem[ans].clear();
		return ans;
	}
	void init(){
		used=-1;
		newnode();
		qb=qf=0;
	}
	void insert(int *s,int n,int val){
		int now=0;
		for(int i=0;i<n;i++){
			if(mem[now].nxt[s[i]]==-1) mem[now].nxt[s[i]]=newnode();
			now=mem[now].nxt[s[i]];
		}
		mem[now].cnt+=val;
		return;
	}
	void build(){
		mem[0].fail=0;
		for(int i=0;i<m;i++){
			if(mem[0].nxt[i]==-1) mem[0].nxt[i]=0;
			else{
				mem[mem[0].nxt[i]].fail=0;
				q[qb++]=mem[0].nxt[i];
			}
		}
		while(qb>qf){
			int u=q[qf++];
			mem[u].cnt+=mem[mem[u].fail].cnt;
			for(int i=0;i<m;i++){
				if(mem[u].nxt[i]==-1) mem[u].nxt[i]=mem[mem[u].fail].nxt[i];
				else{
					mem[mem[u].nxt[i]].fail=mem[mem[u].fail].nxt[i];
					q[qb++]=mem[u].nxt[i];
				}
			}
		}
	}
	void calc_dp(){
		for(int i=0;i<=used;i++){
			for(int k=mem[i].cnt;k<=p;k++) dp[i][0][k]=1;
		}
		int x,y;
		for(int j=1;j<NN;j++){
			for(int i=0;i<=used;i++){
				for(int k=0;k<=p;k++){
					for(int t=0;t<m;t++){
						x=mem[i].nxt[t];
						y=k+mem[x].cnt;
						if(y<=p) add(dp[i][j][k],dp[x][j-1][y]);
					}
				}
			}
		}
	}
	int calc(int n){
		if(!n) return 0;
		int ans=0;
		for(int i=1;i<m;i++){
			int x=mem[0].nxt[i];
			int y=mem[x].cnt;
			if(y<=p) add(ans,dp[x][n-1][y]);
		}
		add(ans,calc(n-1));
		return ans;
	}
	int calc(NUM &num,bool st){
		int now=0;
		int val=0;
		int nxt,nval;
		int ans=0;
		for(int i=0;i<num.len;i++){
			for(int j=0+(i==0);j<num.v[i];j++){
				nxt=mem[now].nxt[j];
				nval=val+mem[nxt].cnt;
				if(nval<=p) add(ans,dp[nxt][num.len-i-1][nval]);
			}
			now=mem[now].nxt[num.v[i]];
			val+=mem[now].cnt;
			if(val>p) break;
		}
		add(ans,calc(num.len-1));
		if(st&&val<=p) add(ans,1);
		return ans;
	}
}ac;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	scanf("%d%d%d",&n,&m,&p);
	L.input();
	R.input();
	ac.init();
	for(int i=0;i<n;i++){
		int len;
		scanf("%d",&len);
		for(int j=0;j<len;j++) scanf("%d",&a[j]);
		int val;
		scanf("%d",&val);
		ac.insert(a,len,val);
	}
	ac.build();
	ac.calc_dp();
	int ans=ac.calc(R,1)-ac.calc(L,0);
	if(ans<0) ans+=mod;
	printf("%d\n",ans);
    return 0;
}