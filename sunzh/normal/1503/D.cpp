#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define fail printf("-1\n"),exit(0);
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int f[200010];
int a[200010],sfm[200010];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		if(x>n&&y>n) fail
		if(x>y) swap(x,y),a[x]=1;
		else a[x]=0;
		f[x]=y;
	} 
	for(int i=n;i>=1;--i) sfm[i]=max(sfm[i+1],f[i]);
	int mx=0x3f3f3f3f,my=0x3f3f3f3f,lx=0,ly=0,sx=0,sy=0,prem=0x3f3f3f3f;
	int ans=0;
	for(int i=1;i<=n;++i){
		prem=min(prem,f[i]);
		if(mx>my) swap(mx,my),swap(lx,ly),swap(sx,sy);
		if(f[i]<mx){
			mx=f[i],++lx,sx+=a[i];
		}
		else if(f[i]<my){
			my=f[i],++ly,sy+=a[i];
		}
		else fail
		if(prem>sfm[i+1]){
			ans+=min(sx+ly-sy,sy+lx-sx);
			sx=sy=lx=ly=0;mx=my=0x3f3f3f3f;
//			continue ;
		}
	} 
	printf("%d\n",ans);
}