#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;typedef long long LL;typedef double DB;const int N = 111;const int MO = 998244353;typedef bitset<N> B;
int mul(int x,int y){return (LL)x*y%MO;}
int fpow(int x,int y=MO-2){int z=1;while(y){if(y&1)z=mul(z,x);x=mul(x,x);y>>=1;}return z;}
int n,q,m,w,a[N],f[N],g[N],h[N];B d[N],t,c[N];
pair<int,int> solve(B u){int i,j,x,y,l,r;B b;j=0;for(i=1;i<=q;i++)if(!a[i]&&(d[i]&u)==d[i]&&d[i].count()>d[j].count())j=i;if(!j)return make_pair(1,u.count());
	a[j]=1;m=1;c[1]=d[j];b=u^c[1];while(1){	x=1;for(i=1;i<=q;i++){if(!a[i]&&(d[i]&u)==d[i]){if((d[i]&b)==d[i])continue;
				for(j=1;j<=m;j++){t=d[i]&c[j];h[j]=0;if(t==c[j])h[j]=2;else if(t.count())h[j]=1;}l=m+1,r=0;for(j=1;j<=m;j++)if(h[j])l=min(l,j),r=max(r,j);
				for(j=l+1;j<=r-1;j++)if(h[j]!=2)return make_pair(0,1);if((d[i]&b).count()){if(l==1&&(h[l]==2||r==1)){
						if(h[r]==1){for(j=m;j>r;j--)c[j+1]=c[j];m++;c[r+1]=c[r]&(~d[i]);c[r]&=d[i];}for(j=m;j>=1;j--)c[j+1]=c[j];m++;c[1]=b&d[i];b&=~d[i];}
					else{if(r==m&&(h[r]==2||l==m)){m++;c[m]=b&d[i];b&=~d[i];if(h[l]==1){for(j=m;j>l;j--)c[j+1]=c[j];m++;c[l+1]=c[l]&d[i];c[l]&=~d[i];}}
						else return make_pair(0,1);}a[i]=1,x=0;break;}
				if(l==r){if(h[l]==2)a[i]=1;continue;}if(h[r]==1){for(j=m;j>r;j--)c[j+1]=c[j];m++;c[r+1]=c[r]&(~d[i]);c[r]&=d[i];}
				if(h[l]==1){for(j=m;j>l;j--)c[j+1]=c[j];m++;c[l+1]=c[l]&d[i];c[l]&=~d[i];}a[i]=1,x=0;break;}}if(x)break;}pair<int,int> p;x=1;if(m>1)x=2;
	B cc[m+1],bb=b;int mm=m;for(i=1;i<=mm;i++)cc[i]=c[i];for(i=1;i<=mm;i++){p=solve(cc[i]);x=mul(x,p.first);x=mul(x,f[p.second]);}p=solve(bb);
	x=mul(x,p.first);return make_pair(x,p.second+1);}
int main(){int i,j,k,x,y;pair<int,int> p;n=105;f[0]=1;for(i=1;i<=n;i++)f[i]=mul(f[i-1],i);g[n]=fpow(f[n]);for(i=n;i>=1;i--)g[i-1]=mul(g[i],i);
	scanf("%d%d",&n,&q);for(i=1;i<=q;i++){scanf("%d",&x);while(x--){scanf("%d",&y);d[i][y]=1;}}
	for(i=1;i<=n;i++)t[i]=1;p=solve(t);printf("%d\n",mul(p.first,f[p.second]));return 0;}