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
#define vc vector
#define Mod 1000000007
int T,n,m;
int a[MN];
char ch[MN];
map<int,int>vis;
signed main(){
	T=read();
	while(T--){
		n=read();
		vis.clear();
		for(int i=1;i<=n;++i)a[i]=read();
		int s=a[1];
		int f=1;
		vis[0]=1;
		for(int i=2;i<=n;++i){
			int to=(f*2-vis[s]+Mod)%Mod;	
		//	vis[s]=(vis[s]+f)%Mod;
			vis[s]=f;
			s=(s+a[i]);
			f=to;
		}
		printf("%lld\n",f);
	}
	return 0;
}