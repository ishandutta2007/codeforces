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
int T,n,m;
int x[MN],y[MN],p[MN];
int dis(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i)
		x[i]=read(),y[i]=read();
	for(int i=1;i<=n;++i)p[i]=i;
	for(int i=1;i<=n;++i){
		cout<<p[i]<<" ";
		for(int j=i+1;j<=n;++j)
			if(dis(p[i],p[j])>dis(p[i],p[i+1]))swap(p[i+1],p[j]);
	}
	return 0;
}