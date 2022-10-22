#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<unordered_map>
#include<chrono>
#include<queue>
#include<random>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
int a[1000010];
int p[1000010],tot,mu[1000010];bool vis[1000010];
void prework(int x){
	for(int i=2;i<=x;++i){
		if(!vis[i]) p[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&p[j]*i<=x;++j){
			vis[i*p[j]]=1;
			if(i%p[j]==0) {
				mu[i*p[j]]=0;
				break ;
			}
			else mu[i*p[j]]=-mu[i];
		}
	}
}
bool used[1000010];
// auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
// const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
signed main(){
	// freopen("ex_c4.in","r",stdin);
	prework(1000000);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int ans=0;
	for(int i=1;i<=(n<=2000?60:10)&&i<=n;++i){
		int po=rnd()%n+1;
		while(used[po]){
			po=rnd()%n+1;
		}
		used[po]=1;
		vector<int>fac;
		int tmp=a[po];
		int f=1;
		for(int j=1;j<=tot;++j) if(tmp%p[j]==0){
			while(tmp%p[j]==0) tmp/=p[j];
			fac.pb(p[j]);f=f*p[j];
		}
		if(tmp>1) fac.pb(tmp),f=f*tmp;
		unordered_map<int,int>Map;Map.clear();
		vector<int>d;d.clear();
		for(int j=1;j*j<=a[po];++j){
			if(a[po]%j==0){
				d.pb(j);if(a[po]/j!=j) d.pb(a[po]/j);
			}
		}
		sort(d.begin(),d.end());reverse(d.begin(),d.end());
		// for(int p:d) printf("%d ",p);printf("\n");
		// for(int p:fac) printf("%d ",p);printf("\n");
		// Map[a[po]]++;
		for(int j=1;j<=n;++j) Map[__gcd(a[j],a[po])]++;
		for(int j:fac){
			for(int p:d) if(p%j==0){
				// printf("Map[%d]=%d\n",p,Map[p]);
				Map[p/j]+=Map[p];
			}
		}
		for(int p:d){
			if(Map[p]>=(n+1>>1)){
				// printf("po:%d,p:%d,%d\n",po,p,Map[p]);
				ans=max(ans,p);break ;
			}
		}
		// vector<vector<int> >ve;
		// ve.resize(fac.size());
		// for(int j=1;j<=n;++j){
		// 	int x=a[j];
		// 	for(int l=0;l<(int)fac.size();++l){
		// 		int c=0;
		// 		while(x%fac[l]==0){
		// 			x/=fac[l];++c;
		// 		}
		// 		ve[l].pb(c);
		// 	}
		// }
		// for(int l=0;l<(int)fac.size();++l){
		// 	sort(ve[l].begin(),ve[l].end());
		// 	ve[l][0]=ve[l][(n+1>>1)];
		// // 	// printf("po:%d,l:%d,%d,%d\n",po,l,fac[l],ve[l][0]);
		// }
		// cerr<<fac.size()<<'\n';
		// map<int,int>Map;
		// for(int j=1;j<=n;++j){
		// 	int x=a[j];
		// 	int val=__gcd(x,a[i]);
			// for(int l=0;l<(int)fac.size();++l){
			// 	int c=0;
			// 	while(x%fac[l]==0){
			// 		x/=fac[l];
			// 		++c;if(c<=ve[l][0]) val=val*fac[l];
			// 	}
			// 	// ve[l].pb(c);
			// }
		// 	Map[-val]++;
		// }
		// for(int j:fac){
		// 	map<int,int>::iterator it;
		// 	it=Map.begin();f/=j;
		// 	while(it!=Map.end()){
		// 		int a=-(it->fi),b=(it->se);
		// 		if(b>=(n+1>>1)){
		// 			ans=max(ans,a);break ;
		// 		}
		// 		if(a%j==0){
		// 			Map[-(a/j)]+=b;
		// 		}
		// 		if(__gcd(a,f)==1) Map.erase(it++);
		// 		else ++it;
		// 	}
		// }
		// map<int,int>::iterator it;
		// while(Map.size()){
		// 	it=Map.begin();
		// 	if((it->se)>=(n+1>>1)){
		// 		ans=max(ans,-(it->fi));break ;
		// 	}
		// 	if(-(it->fi)<ans) break ;
		// 	Map.erase(it);
		// }
	}
	// cerr<<ans;
	printf("%lld\n",ans);
}