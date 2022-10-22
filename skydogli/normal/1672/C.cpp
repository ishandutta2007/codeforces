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
int a[MN];
char ch[MN];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		int l=0,r=0;
		for(int i=2;i<=n;++i){
			if(a[i]==a[i-1]&&!l)l=i;
			if(a[i]==a[i-1])r=i;
		}
		if(l!=r)printf("%lld\n",max(r-l-1,1ll));
		else puts("0");
	}
	return 0;
}