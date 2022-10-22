#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<bitset>
#include<cstring>
#include<map>
#include<cmath>
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
int T;
bitset<256>dp[1000010];
char str[1000010];
bool vis[1000010];
int main(){
	T=read();
	while(T--){
		scanf("%s",str+1);
		int n=strlen(str+1),m=0;
		for(int i=1;i<=n;++i) m+=(str[i]-'0'),vis[i]=0;
		if(m==0){
			puts("-1");continue ;
		}
		if(m<=16){
			dp[n+1].reset();dp[n+1][0]=1;
			for(int i=n;i>=1;--i){
				if(str[i]=='0') dp[i]=dp[i+1];
				else{
					dp[i].reset();
					int bt=0;
					for(int j=0;j<=7&&i+j<=n;++j){
						bt=(bt<<1)|(str[i+j]-'0');
						dp[i]|=dp[i+j+1]<<bt;
					}
				}
			}
			int cur=1;
			while(!dp[1][cur]) cur<<=1;
			vector<PII>ans;
			for(int i=1;i<=n;++i){
				int bt=0;
				for(int j=0;j<=7&&i+j<=n;++j){
					bt=(bt<<1)|(str[i+j]-'0');
					if(dp[i+j+1][cur-bt]){
						ans.pb(mp(i,i+j));cur-=bt;i+=j;break ;
					}
				}
			}
			printf("%d\n",ans.size());
			for(PII i:ans) printf("%d %d\n",i.fi,i.se);
		}
		else{
			int cur=1;
			while(cur<m) cur<<=1;
			vector<PII>ans;
			vector<int>p4;
			cur-=m;
			int lst=0;
			for(int i=1;i<=n;++i) if(p4.size()<4){
				if(str[i]=='1') p4.pb(i);lst=i;
			}
			else{
				if(str[i]=='0') ans.pb(mp(i,i));
				else{
					if(str[i+1]=='0'){
						if(i+2<=n&&cur>=3) ans.pb(mp(i,i+2)),cur-=3,i+=2;
						else if(i+1<=n&&cur>=1) ans.pb(mp(i,i+1)),cur--,i++;
						else ans.pb(mp(i,i));
					}
					else{
						if(i+2<=n&&cur>=4) ans.pb(mp(i,i+2)),cur-=4,i+=2;
						else if(i+1<=n&&cur>=1) ans.pb(mp(i,i+1)),cur--,i++;
						else ans.pb(mp(i,i));
					}
				}
			}
			if(cur>2) exit(114514);
			if(cur==0) for(int i=1;i<=lst;++i) ans.pb(mp(i,i));
			else if(cur==1){
				ans.pb(mp(p4[0],p4[0]+1));vis[p4[0]]=vis[p4[0]+1]=1;
				for(int i=1;i<=lst;++i) if(!vis[i]) ans.pb(mp(i,i));
			}
			else{
				ans.pb(mp(p4[0],p4[0]+1));vis[p4[0]]=vis[p4[0]+1]=1;
				ans.pb(mp(p4[2],p4[2]+1));vis[p4[2]]=vis[p4[2]+1]=1;
				for(int i=1;i<=lst;++i) if(!vis[i]) ans.pb(mp(i,i));
			}
			printf("%d\n",ans.size());
			for(PII i:ans) printf("%d %d\n",i.fi,i.se);
		}
	}
}