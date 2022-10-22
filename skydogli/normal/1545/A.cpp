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
int b[MN],c[MN];
signed main(){
	T=read();
	while(T--){
		int N=read();
		n=0;m=0;
		for(int i=1;i<=N;++i){
			if(i&1)b[++n]=read();
			else c[++m]=read();
		}
		sort(b+1,b+1+n);sort(c+1,c+1+m);
		bool GG=0;
		c[m+1]=1e9;
		for(int i=1;i<=n;++i)
			if(b[i]>c[i]||b[i]<c[i-1])GG=1;
		puts(!GG?"YES":"NO");
	}
	return 0;
}