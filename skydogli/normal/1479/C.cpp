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
#define piii pair<pii,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
int T,n,m,l,r;
int a[MN];
vector<piii >ans;
map<pii,int>vis;
int chk(int x){
	if(1<x&&x<n-1){
		return n-x;
	}
	return x;
}
signed main(){
	l=read(),r=read();
	n=22;
	for(int i=2;i<n;++i){
		ans.pb(mp(mp(i,n+1),l));
	}
	ans.pb(mp(mp(1,n+1),l));
	int v=r-l;
	for(int i=2;i<n;++i)
		for(int j=2;j<i;++j){
	//		if((1<<j-2)<=v)
				ans.pb(mp(mp(i,j),(1<<j-2)));	
		}
	int tmp=0;
	for(int i=n-1;i>=2;--i){
		if((v>>i-2)&1){
	//		cerr<<"! "<<i<<endl;
//			for(int j=i-1;j>=2;--j)
//				ans.pb(mp(mp(1ll,j),tmp+(1<<j-2)));
			ans.pb(mp(mp(1ll,i),tmp+1));
			tmp+=(1<<i-2);
		}
	}
	n++;
	puts("YES");
	printf("%lld %lld\n",n,(int)ans.size());
	for(int i=0;i<ans.size();++i){
		printf("%lld %lld %lld\n",chk(ans[i].x.x),chk(ans[i].x.y),ans[i].y);
	}
	return 0;
}