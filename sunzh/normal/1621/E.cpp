#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
#define double long double
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m;
int a[100010];
struct fs{
	int fz,fm;
};
bool operator <(fs x,fs y){
	return x.fz*y.fm<x.fm*y.fz;
}
bool operator <=(fs x,fs y){
	return x.fz*y.fm<=x.fm*y.fz;
}
bool operator >=(fs x,fs y){
	return x.fz*y.fm>=x.fm*y.fz;
}
bool operator >(fs x,fs y){
	return x.fz*y.fm>x.fm*y.fz;
}
vector<int>ve[100010];
vector<int>ans[100010];
pair<fs,int> d[100010];
const double Eps=1e-10;
int pp[100010];
bool mv[100010],pr[100010];
signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i) a[i]=read();
		sort(a+1,a+n+1);reverse(a+1,a+n+1);
		for(int i=1;i<=m;++i){
			int k=read();ve[i].assign(k+1,0);ans[i].assign(k,0);
			int s=0;
			for(int j=0;j<k;++j) ve[i][j]=read(),s+=ve[i][j];ve[i][k]=s;
			d[i]=mp(fs{s,k},i);
		}
		sort(d+1,d+m+1);reverse(d+1,d+m+1);
		mv[m+1]=1;
		int cnt=0,ps=0;
		for(int i=1;i<=m;++i){
			pr[i]=0;
			if(d[i].fi>fs{a[i-cnt],1}) ++cnt,ps=i;
			pp[i]=i-cnt;
			if(!cnt) pr[i]=1;
		}
		pp[m+1]=pp[m]+1;
		pr[0]=1;
		if(cnt>1){
			for(int i=1;i<=m;++i) for(int j=0;j<ve[i].size()-1;++j) putchar('0');printf("\n");
		}
		else if(cnt){
			mv[m+1]=1;
			for(int i=m;i>=1;--i) if(fs{a[i],1}>=d[i].fi) mv[i]=mv[i+1];else mv[i]=0;
			for(int i=1;i<=ps;++i){
				int k=ans[d[i].se].size(),p=d[i].se;
				for(int j=0;j<k;++j){
					fs ne=fs{(ve[p][k]-ve[p][j]),(k-1)};
					int l=1,r=m,K=m+1;
					while(l<=r){
						int mid=l+r>>1;
						if(d[mid].fi<=ne) K=mid,r=mid-1;else l=mid+1;
					}
					if(K<=ps) continue ;
					else if(mv[K]&&fs{a[K-1],1}>=ne) ans[p][j]=1;
				}
			}
			for(int i=1;i<=m;++i){
				for(int j=0;j<ans[i].size();++j) putchar(ans[i][j]+'0');
			}
			printf("\n");
		}
		else{
			int lst=0;
			for(int i=1;i<=m;++i){
				int k=ans[d[i].se].size();
				int p=d[i].se;
				for(int j=0;j<k;++j){
					fs ne=fs{(ve[p][k]-ve[p][j]),(k-1)};
					int l=1,r=m,K=m+1;
					while(l<=r){
						int mid=l+r>>1;
						if(d[mid].fi<=ne) K=mid,r=mid-1;else l=mid+1;
					}
					if(K>lst){
						if(fs{a[pp[K>i?K-1:K]],1}>=ne) ans[p][j]=1;
					}
				}
				if(fs{a[i+1],1}<d[i].fi) lst=i;
			}
			for(int i=1;i<=m;++i){
				for(int j=0;j<ans[i].size();++j) putchar(ans[i][j]+'0');
			}
			printf("\n");
		}
	}
}