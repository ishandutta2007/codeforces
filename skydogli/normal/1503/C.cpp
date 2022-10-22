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
int n,c[MN];
pii a[MN];
signed main(){
	n=read();
	int ans=0;
	for(int i=1;i<=n;++i){
		a[i].x=read();c[i]=read();
		a[i].y=i;
		ans+=c[i];
	}	
	sort(a+1,a+1+n);
	int mx=a[1].x+c[a[1].y];
	for(int i=2;i<=n;++i){
		if(a[i].x>mx)ans+=a[i].x-mx;
		mx=max(mx,a[i].x+c[a[i].y]);
	}
	printf("%lld\n",ans);
	return 0;
}