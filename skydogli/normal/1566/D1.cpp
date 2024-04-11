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
pii a[MN];
char ch[MN];
signed main(){
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=m;++i)a[i]=mp(read(),-i);
		sort(a+1,a+1+m);
		int ans=0;
		for(int i=1;i<=m;++i){
			for(int j=1;j<i;++j)
				if(-a[j].y<-a[i].y)ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}