#include<bits/stdc++.h>
const int L=200005;
using namespace std;
int n,m,bin[9],num[9],mp[9][9],
p[9],ed[9][9],cnt[9];
char S[9];
bool vis[9];
inline int rd(){
	scanf("%s",S);return strlen(S);
}
inline bool chk(){
	for(int s=1;s<1<<m;s++){
		n=0;
		for(int i=0;i<m;i++)
		if(s>>i&1){
			n-=num[i+1]-1;
			for(int j=0;j<m;j++)
			if(i^j){
				n+=ed[i+1][j+1];
				if(!(s>>j&1))
				n+=ed[j+1][i+1];
			}
		}
		//cerr<<s<<":"<<n<<endl;
		if(n<0)return 0;
	}return 1;
}
inline bool dec(int u,int v){
	if(!ed[u][v]){
		if(!ed[v][u]--)return 1;
	}else ed[u][v]--;
	return 0;
}
void dfs(int d){
	if(d==m){
		for(int i=1;i<=m;vis[i]=cnt[i]=0,i++)
		for(int j=1;j<=m;j++)ed[i][j]=mp[i][j];
		for(int i=2;i<m;i++)cnt[p[i]]++;
		for(int i=2,j;i<m;i++){
			for(j=1;vis[j]||cnt[j];j++);
			if(dec(j,p[i]))return;
			vis[j]=1,cnt[p[i]]--;
		}
		for(int i=1;;i++)
		if(!vis[i]){
			for(int j=i+1;;j++)
			if(!vis[j]){
				if(dec(i,j))return;
				break;
			}break;
		}/*
		for(int i=2;i<m;i++)
		cerr<<p[i]<<' ';cerr<<endl;
		for(int i=1;i<=m;i++)cerr<<num[i]<<' ';cerr<<endl;
		for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		if(i^j)cerr<<"("<<i<<','<<j<<")"<<ed[i][j]<<endl;*/
		if(!chk())return;
		for(int i=1;i<=m;i++){
			cnt[i]=bin[i];
			for(int j=0;j<mp[i][i];j++)
			printf("%d %d\n",cnt[i],cnt[i]+1),cnt[i]++;
		}
		for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		if(i^j){
			if(mp[i][j]>ed[i][j])
			printf("%d %d\n",bin[i],bin[j]);
			for(;ed[i][j];){
				num[i]--,ed[i][j]--;
				if(chk())printf("%d %d\n",++cnt[i],bin[j]);
				else num[i]++,num[j]--,printf("%d %d\n",bin[i],++cnt[j]);
			}
		}exit(0);
	}
	for(int i=1;i<=m;i++)p[d]=i,dfs(d+1);
}
int main(){/*
	freopen("dat.txt","r",stdin);
	freopen("me.txt","w",stdout);*/
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(i>=bin[m]*10)bin[++m]=i;
		num[m]++;
	}
	if(m<2){
		for(int i=1;i<n;i++)
		printf("%d %d\n",i,i+1);
		return 0;
	}
	for(int i=1;i<n;i++)
	mp[rd()][rd()]++;
	for(int i=1;i<=m;i++)
	num[i]-=mp[i][i];
	dfs(2);puts("-1");
}