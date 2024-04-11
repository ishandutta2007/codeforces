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
#define MN 205
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int n,tot;
struct node{
	int l,r,id;
}a[MN];
int f[MN][MN];
bool cmp(node a,node b){return a.r<b.r;}
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		int pos=read(),len=read();
		a[++tot].l=pos-len;a[tot].r=pos;a[tot].id=i;
		a[++tot].l=pos;a[tot].r=pos+len;a[tot].id=i;
	}
	sort(a+1,a+1+tot,cmp);
	f[0][0]=0;
	int ans=0;
	a[0].l=a[0].r=-1e9;
	for(int i=0;i<=tot;++i){
//		cerr<<i<<": "<<a[i].l<<" "<<a[i].r<<endl;
		for(int j=0;j<=i;++j){
//			cerr<<"f "<<i<<" "<<j<<": "<<f[i][j]<<endl;
			if(i&&j&&(a[j].r==a[i].r||a[j].id==a[i].id))continue;
			ans=max(ans,f[i][j]);
			for(int k=i+1;k<=tot;++k){
				if(a[i].r==a[k].r||a[j].r>=a[k].l||a[i].id==a[k].id||a[j].id==a[k].id)continue;	
				f[k][i]=max(f[k][i],f[i][j]+a[k].r-max(a[k].l,a[i].r));
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}