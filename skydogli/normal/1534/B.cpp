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
#define MN 400005
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
		int ans=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		a[n+1]=0;
		for(int i=1;i<=n;++i)
			if(a[i]>a[i-1]&&a[i]>a[i+1]){
				int t=max(a[i-1],a[i+1]);
				ans+=a[i]-t;
				a[i]=t;
			}
		for(int i=1;i<=n+1;++i)
			ans+=abs(a[i]-a[i-1]);
		printf("%lld\n",ans);
	}
	return 0;
}