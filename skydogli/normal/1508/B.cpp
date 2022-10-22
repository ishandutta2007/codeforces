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
bool vis[MN];
signed main(){
	T=read();
	while(T--){
		n=read();int k=read();
		int ti=0,v=1;while(v<k)v<<=1,ti++;
		if(ti>n-1){puts("-1");continue;}
		k--;
		vc pos;pos.pb(0);pos.pb(n);
		for(int i=1;i<=n;++i)vis[i]=0;
		while(k){
			int v=1,p=n;
			while(v*2<=k)v<<=1,ti++,p--;
			k-=v;
			vis[p]=1;
			//pos.push_back(p);
		}
		vis[n+1]=0;
		for(int i=1;i<=n;++i){
			int j=i;
			while(vis[j+1])j++;
			for(int k=j;k>=i;--k)printf("%lld ",k);
			i=j;
		}
		puts("");
	/*	sort(pos.begin(),pos.end());
		for(int i=0;i+1<pos.size();++i){
			int s=pos[i]+1,t=pos[i+1];
			for(int j=t;j>=s;--j)printf("%d ",j);
		}
		puts("");*/
	}
	return 0;
}