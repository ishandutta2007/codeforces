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
int T,n,m;
int a[MN],b[MN];
int vis[MN],cnt[MN],nxt[MN];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read(),vis[i]=0,cnt[i]=1;
		for(int i=1;i<=n;++i)b[i]=read();
		for(int i=n;i;--i){
			nxt[i]=vis[a[i]];
			vis[a[i]]=i;
		}
		int pos=1,GG=0;
		for(int i=1;i<=n&&!GG;++i){
			while(a[pos]!=b[i]){
				if(!nxt[pos]){GG=1;break;}
				cnt[nxt[pos]]+=cnt[pos];
				pos++;
			}
			if(a[pos]==b[i])cnt[pos]--;
			if(!cnt[pos])pos++;
			if(GG)break;
		}
		puts(GG?"NO":"YES");
	}
	return 0;
}