#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
#define mn 65
int T,n,m,p,id[MN];
char G[MN][mn];
bitset<MN>bi[mn],w,all;
int cnt[1<<15];
int ans[mn];
//bool GG[mn];
bool chk(int x,int r){
	vc st(0);
	for(int j=1;j<=m;++j)
		if(G[x][j]){
			st.pb(j);
//			if(GG[j])return 0;
		}
	random_shuffle(st.begin(),st.end());
	if(!st.size())return 0;
	int lst=0;
	for(int i=0;i<(1<<st.size());++i){
		if(cnt[i]!=r)continue;	
		w.set();
		for(int j=0;j<st.size();++j){
			if((i>>j)&1)w&=bi[st[j]];
		}
		if(w.count()>=(n+1)/2){
			for(int i=1;i<=m;++i)ans[i]=0;
			for(int j=0;j<st.size();++j)
				if((i>>j)&1)ans[st[j]]=1;
			return 1;
		}
	}
	return 0;
}
signed main(){
	srand(time(0));
	n=read();m=read();p=read();
	for(int i=1;i<=n;++i){
		scanf("%s",G[i]+1);
		for(int j=1;j<=m;++j){
			G[i][j]-='0';
			if(G[i][j])bi[j].set(i);
		}
		id[i]=i;
	}
	random_shuffle(id+1,id+1+n);	
	for(int i=1;i<(1<<15);++i)
		cnt[i]=cnt[i>>1]+(i&1);
	int ans=0;
	for(int i=1;i<=min(10ll,n);++i){
		while(chk(id[i],ans+1))ans++;	
	}
	for(int i=1;i<=m;++i)printf("%lld",::ans[i]);
	return 0;
}