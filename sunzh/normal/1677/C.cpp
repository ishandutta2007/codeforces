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
int n;
int ca[100010],cb[100010];
int val[100010];
map<PII,int>Map;
vector<int>vec[100010];
bool ok[100010];
int col[100010];
int dw,up;
void dfs(int x,int cl){
	if(col[x]==-1){
		col[x]=cl;
		for(int v:vec[x]){
			dfs(v,cl^1);
		}
	}
	return ;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) ca[i]=read();
		for(int i=1;i<=n;++i) cb[i]=read(),val[i]=0,vector<int>().swap(vec[i]),col[i]=-1,ok[i]=0;Map.clear();
		up=n,dw=1;
		for(int i=1;i<=n;++i){
			if(ca[i]!=cb[i]){
				ok[ca[i]]=ok[cb[i]]=1;
				vec[ca[i]].pb(cb[i]);
				vec[cb[i]].pb(ca[i]);
				Map[mp(min(ca[i],cb[i]),ca[i]+cb[i]-min(ca[i],cb[i]))]++;
			}
		}
		vector<PII>v2,v1;
		for(auto i:Map){
			if(i.fi.fi==i.fi.se) continue ;
			if(i.se==2) v2.pb(i.fi);
			else v1.pb(i.fi);
		}
		for(PII i:v2){
			val[i.fi]=up--;ok[i.fi]=ok[i.se]=0;
			val[i.se]=dw++;
		}
		for(int i=1;i<=n;++i) if(ok[i]&&col[i]==-1){
			dfs(i,0);
		}
		int L1=dw,R1,L2,R2=up;
		R1=dw,L2=up;
		for(int i=1;i<=n;++i) if(ok[i]){
			if(col[i]==0) ++R1;else --L2;
		}
		for(int i=1;i<=n;++i) if(col[i]==0&&!val[i]){
			for(int j:vec[i]) if(col[i]==col[j]&&!val[j]){
				val[i]=L1++;val[j]=--R1;
			}
		}
		for(int i=1;i<=n;++i) if(col[i]==0&&!val[i]){
			val[i]=L1++;
		}
		for(int i=1;i<=n;++i) if(col[i]==1&&!val[i]){
			for(int j:vec[i]) if(col[i]==col[j]&&!val[j]){
				val[i]=++L2;val[j]=R2--;
			}
		}
		for(int i=1;i<=n;++i) if(col[i]==1&&!val[i]){
			val[i]=R2--;
		}
		long long ans=0;
		for(int i=1;i<=n;++i){
			ans+=abs(val[ca[i]]-val[cb[i]]);
		}
		printf("%lld\n",ans);
	}
}