#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline pair<int,int> Min(pair<int,int> a,pair<int,int> b){return a<b?a:b;}
const int o=3e5+10;
int n,q,k,a[o],b[o],c[o],hd=1,tl,Q[o],lg[o];pair<int,int> st[o][20];
long long dp[o],ans[o];vector<pair<int,pair<int,int> > > v[o];
inline pair<int,int> query(int l,int r){int t=lg[r-l+1];return Min(st[l][t],st[r-(1<<t)+1][t]);}
int main(){
	read(n);read(q);read(k);
	lg[0]=-1;for(int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
	for(int i=0;i<n;++i) read(a[i]);
	for(int i=0;i<n;++i){
		if(hd<=tl&&Q[hd]==i-k-1) ++hd;
		for(;hd<=tl&&a[Q[tl]]>=a[i];--tl);
		Q[++tl]=i;b[i]=a[Q[hd]];
	}
	for(int i=1,l,r;i<=q;++i){
		read(l);read(r);ans[i]=a[--l];--r;
		r=l+(r-l)/k*k;l+=k;
		if(l<=r) v[l%k].push_back(make_pair(i,make_pair(l/k+1,r/k+1)));
	}
	for(int i=0,cnt=0;i<k;++i,cnt=0) if(v[i].size()){
		for(int j=i;j<n;j+=k) c[++cnt]=b[j];
		for(int j=1;j<=cnt;++j) st[j][0]=make_pair(c[j],j);
		for(int j=1;j<20;++j) for(int $=1;$<=cnt;++$)
			st[$][j]=($+(1<<j-1)<=cnt?Min(st[$][j-1],st[$+(1<<j-1)][j-1]):st[$][j-1]);
		dp[cnt+1]=0;
		for(int j=cnt,l,r,md;j;dp[j]=dp[l]+c[j]*1ll*(l-j),--j)
			for(l=j+1,r=cnt+1;l<r;) if(query(j+1,md=l+r>>1).first<c[j]) r=md;else l=md+1;
		for(int j=0,$=v[i].size(),l,r,p;j<$;++j)
			p=query(l=v[i][j].second.first,r=v[i][j].second.second).second,ans[v[i][j].first]+=dp[l]-dp[p]+(r-p+1)*1ll*c[p];
	}
	for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
	return 0;
}