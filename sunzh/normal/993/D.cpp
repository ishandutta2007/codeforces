#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
PII a[100];
int f[110][110];
int siz[110];
vector<PII>vec[110];
int m;
bool check(int x){
	int c=0;
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	int res=100;
	for(int i=1;i<=m;++i){
		c+=siz[i];
		for(int j=0;j<=c;++j){
			int s=0;
			for(int k=0;k<=siz[i]&&j-k>=c-j;++k){
				if(k) s+=vec[i][k-1].fi-x*vec[i][k-1].se;
				f[i][j]=min(f[i][j],f[i-1][j-k]+s);
				if(i==m) res=min(res,f[i][j]);
			}
		}
	}
	return res<=0;
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i].fi=1000*read();
	for(int i=1;i<=n;++i) a[i].se=read();
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if(a[i].fi!=a[i-1].fi) ++m;
		vec[m].pb(a[i]);++siz[m];
	}
	int l=0,r=1e11,res=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	print(res);
}