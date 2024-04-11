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
#define MN 1000005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
int a[MN];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+1+n);
		int ans=a[n];
		for(int i=1;i<=n;++i)ans+=a[i]*((n-i)-(i-1));
		printf("%lld\n",ans);
	}
	return 0;
}