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
int ti[305][305];
signed main(){
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n*m;++i)a[i]=mp(read(),i);
		sort(a+1,a+1+n*m);
		int x=1,p=1;
		for(int i=1,j=1;i<=n*m;i=j+1){
			j=i;while(j<n*m&&a[j+1].x==a[i].x)j++;
			int cnt=j-i+1,o=i;
			while(cnt){
				int w=min(cnt,m-p+1);
		//		cerr<<"w: "<<w<<endl;
				for(int i=p+w-1;i>=p;--i){
		//			cerr<<"ti "<<x<<" "<<i<<": "<<a[o].y<<endl;
					ti[x][i]=a[o++].y;
				}
				p+=w;
				cnt-=w;
				if(p==m+1)x++,p=1;
		//		cerr<<"p: "<<p<<endl;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)
				for(int k=1;k<j;++k)
					if(ti[i][j]>ti[i][k])ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}