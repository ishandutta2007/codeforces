#include<bits/stdc++.h>
const int N=200005,V=100,M=10007;
using namespace std;
map<int,int>cnt[V];
vector<int>ha[V][M],hb[V][M];
int n,sum[V],nxt[N],lst,now,ta,tb;
char S[N];
long long ans;
inline void ins(int x,int y){
	int ta=y%M;
	for(int i=0;i<ha[x][ta].size();i++)
	if(ha[x][ta][i]==y){hb[x][ta][i]++;return;}
	ha[x][ta].push_back(y),hb[x][ta].push_back(1);
}
inline int qry(int x,int y){
	int ta=y%M;
	for(int i=0;i<ha[x][ta].size();i++)
	if(ha[x][ta][i]==y)return hb[x][ta][i];
	return 0;
}
int main(){
	scanf("%s",S+1);
	n=strlen(S+1);
	for(int i=1;i<=n;i++){
		nxt[i]=lst;if(S[i]=='1')lst=i;
		for(int j=1;j<V;j++){
			ins(j,sum[j]);
			sum[j]-=1;
			if(S[i]=='1')sum[j]+=j;
			ans+=qry(j,sum[j]);
		}
	}nxt[n+1]=lst;
	for(int i=1,j;i<=n;i++){
		j=nxt[i+1];now=1;
		for(;j&&now*V<=n;j=nxt[j],now++){
			ta=(i-j+now)/now;
			tb=(i-nxt[j])/now;
			//cerr<<j<<'~'<<i<<":"<<ta<<','<<tb<<endl;
			ta=max(ta,V);
			if(ta<=tb)ans+=tb-ta+1;
		}
	}printf("%lld",ans);
}