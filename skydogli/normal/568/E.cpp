#include<bits/stdc++.h>
using namespace std;
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
#define vc vector
int n,m;
int a[MN],b[MN],v[MN],N,pre[MN],f[MN];
bool B[MN];
int sum[MN];
int ask(int x){
	int res=0;
	while(x){
		res=max(res,sum[x]);
		x-=x&(-x);
	}
	return res;
}
void add(int x,int v){
	while(x<=N){
		sum[x]=max(sum[x],v);
		x+=x&(-x);
	}
}
#define itset multiset<int>::iterator
#define rint register int
multiset<int>S;
vector<int>loc[MN];
int ps[MN];
int vis[MN];
void del(int n,int l,int r){
	for(int i=l;i<=r;++i)
		for(auto j:loc[i])
			if(j<=n)vis[f[j]]--;
			else break;
}
signed main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]!=-1)v[++N]=a[i];	
	}
	m=read();
	for(int i=1;i<=m;++i)v[++N]=b[i]=read();
	sort(v+1,v+1+N);
	N=unique(v+1,v+1+N)-v-1;
	for(int i=1;i<=n;++i)if(a[i]!=-1)a[i]=lower_bound(v+1,v+1+N,a[i])-v;
	for(int i=1;i<=n;++i)if(a[i]!=-1)loc[a[i]].pb(i);
	int mx=0;
	for(int i=1;i<=m;++i){
		b[i]=lower_bound(v+1,v+1+N,b[i])-v;
		B[b[i]]=1;
		mx=max(mx,b[i]);
		S.insert(b[i]);
	}
	for(int i=1;i<=n;++i){
		if(a[i]!=-1){
			int w=ask(a[i]-1)+1;
			f[i]=w;
			add(a[i],w);
			vis[f[i]]++;
		}
		else{
			for(rint i=1;i<=N;++i)
				ps[i]=max(ps[i-1],sum[i]);
			for(rint j=1;j<=N;++j){
				if(B[j]&&ps[j-1]+1>sum[j]){
					sum[j]=ps[j-1]+1;
				}
					rint t=j+(j&(-j));
					if(t<=N)sum[t]=max(sum[t],sum[j]);
			}
			f[i]=sum[mx];
		}
	}
	int ans=0,pos=0;
	for(int i=1;i<=n;++i)if(ans<f[i])ans=f[i],pos=i;
	int now=ans,v=N+1;
	for(int i=pos+1;i<=n;++i)if(a[i]!=-1)vis[f[i]]--;
	for(int i=pos;i&&now;--i){
		bool flag=(a[i]!=-1);
		if((a[i]!=-1&&f[i]==now)||(a[i]==-1&&!vis[now])){
			if(a[i]==-1){
				itset it=S.lower_bound(v);
				assert(S.size()&&it!=S.begin());
				it--;
				a[i]=*it;
				del(i,a[i],v-1);
				v=a[i];
				S.erase(it);
			}
			else {
				del(i,a[i],v-1);
				v=a[i];	
			}
			now--;
		}
		if(flag&&a[i]<v)vis[f[i]]--;
	}
	for(int i=1;i<=n;++i){
		if(a[i]==-1){a[i]=*S.begin();S.erase(S.begin());}
		printf("%d%c",::v[a[i]],i==n?'\n':' ');
	}
	return 0;
}