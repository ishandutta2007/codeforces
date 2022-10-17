#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 1e-8
const int inf = 0xfffffff;
const ll INF = 1ll<<61;
using namespace std;
#define MOD 1000000007
int nn[355];
int b[355];
int c[355];
int father[355];
int in[355];
ll dp[1000005];
bool flag;
void init() {
	memset(nn,0,sizeof(nn));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(in,0,sizeof(in));
	memset(father,0,sizeof(father));
	memset(dp,0ll,sizeof(dp));
	flag=0;
}
void input(int &n,int &q,int &t) {
	scanf("%d%d%d",&n,&q,&t);
	for(int i=1;i<=n;i++){
		scanf("%d",&nn[i]);
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&b[i],&c[i]);
		father[b[i]]=c[i];
		in[c[i]]++;
	}
}
void cal(int &n,int &q,int &t){
	for(int i=0;i<q;i++){
		int tmp=0;
		for(int j=1;j<=n;j++){
			if(father[j]&&in[j]==0) {
				tmp=j;
				break;
			}
		}
		if(!tmp){
			puts("0");
			flag=1;
			return;
		}
		int pre=father[tmp];
		in[pre]--;
		father[tmp]=0;
		t-=nn[tmp];
		nn[pre]+=nn[tmp];
		if(t<0){
			puts("0");
			flag=1;
			return;
		}
	}
}
void DP(int &n,int &t){
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(nn[i]>t){
			continue;
		}
		for(int j=0;j+nn[i]<=t;j++){
			dp[j+nn[i]]=(dp[j+nn[i]]+dp[j])%MOD;
		}
	}
}
void output(int &t){
	printf("%I64d\n",dp[t]);
}
int main(){
	int n,q,t;
	init();
	input(n,q,t);
	cal(n,q,t);
	if(flag){
		return 0;
	}
	DP(n,t);
	output(t);
	return 0;
}