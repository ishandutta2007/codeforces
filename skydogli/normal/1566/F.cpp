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
int a[MN],suf[MN];
set<int>A;
pii b[MN];
int f[MN][2];
signed main(){
	T=read();
	while(T--){
		n=read();m=read();
		A.clear();
		for(int i=1;i<=n;++i){
			a[i]=read();
			A.insert(a[i]);
		}
		a[++n]=-5e9;a[++n]=5e9;
		A.insert(-5e9);A.insert(5e9);
		sort(a+1,a+1+n);
		int t=m,m=0;
		for(int i=1;i<=t;++i){
			int l=read(),r=read();
			if((*A.lower_bound(l))<=r)continue;
			b[++m]=mp(l,r);
		}
		sort(b+1,b+1+m);
		int l=1;
		suf[m+1]=1e10;
		for(int i=m;i;--i)suf[i]=min(suf[i+1],b[i].y);
		for(int i=1;i<n;++i){
			int r=l;
			assert(b[l].x>a[i]);
			while(r<=m&&b[r].y<a[i+1])r++;
			f[i+1][0]=f[i][0]+max(a[i+1]-suf[l],0ll);	
			f[i+1][1]=f[i][0]+max(a[i+1]-suf[l],0ll)*2;
			for(int j=l;j<r;++j){
				f[i+1][0]=min(f[i+1][0],f[i][1]+b[j].x-a[i]+max(a[i+1]-suf[j+1],0ll));
				f[i+1][0]=min(f[i+1][0],f[i][0]+(b[j].x-a[i])*2+max(a[i+1]-suf[j+1],0ll));
				f[i+1][1]=min(f[i+1][1],f[i][0]+(b[j].x-a[i])*2+max(a[i+1]-suf[j+1],0ll)*2);
				f[i+1][1]=min(f[i+1][1],f[i][1]+b[j].x-a[i]+max(a[i+1]-suf[j+1],0ll)*2);
			}
			l=r;
			if(l==m+1){
				n=i+1;break;
			}
		}
		printf("%lld\n",min(f[n][0],f[n][1]));
	}
	return 0;
}