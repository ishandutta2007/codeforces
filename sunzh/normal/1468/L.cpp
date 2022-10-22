#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<chrono>
#include<map>
#include<random>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
#define ll __int128
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rnd(SEED);
//int T;
int n;
//int ans;
int Rand(int s){
	if(n==1) return -1;
	int c=rnd()%s+1;
	while(c==2) c=rnd()%s+1;
	return c;
}
int qpow(int x,int k,int mod){
	int t=x,r=1;
	while(k){
		if(k&1) r=(__int128)r*x%mod;
		x=(__int128)x*x%mod;
		k>>=1;
	}
	return r;
}
int prime[8]={2ll,3ll,7ll,11ll,13ll,61ll,2333ll,24251ll};
bool Miller_Rabin(int x){
//	if(x==46856248255981) return 0;
	if(x<=2) return 1;
	if(x%2==0) return false;
	for(int i=0;i<8;++i){
		if(x==prime[i]) return 1;
		bool f=0;
		if(x%prime[i]==0||qpow(prime[i]%x,x-1,x)!=1) return false ;
		int k=x-1;
		while(!(k&1)){
			int t=qpow(prime[i]%x,k>>1,x);
			if(t!=1&&t!=x-1) return false;
			if(t!=1) break ;
			k>>=1;
		}
	}
	return true ;
}
int Pollard_Rho(int x){
	if(x==1) return 0;
	if(x%2==0) return 2;
	if(x%3==0) return 3;
	if(x%5==0) return 5;
	int c=Rand(x);
	int a=rand()%(x-2)+1,b=a;
	a=((__int128)a*a+c)%x,b=((__int128)b*b+c)%x,b=((__int128)b*b+c)%x;
	for(int lim=1;a!=b;lim=min(lim<<1,128ll)){
		int cnt=1;
		for(int i=0;i<lim&&a!=b;++i){
			int tmp=(__int128)cnt*llabs(a-b)%x;
			if(!tmp) break ;
			cnt=tmp;
			a=((__int128)a*a+c)%x,b=((__int128)b*b+c)%x,b=((__int128)b*b+c)%x;
		}
		int d=__gcd(cnt,x);
		if(d!=1&&d!=x) return d;
	}
	return x;
}
set<int>st;
set<int>pm[1010];
void Find(int x){
	if(x==1) return ;
	if(Miller_Rabin(x)){
		st.insert(x);
		return ;
	}
	int p=x;
	while(p>=x){
		p=Pollard_Rho(x);
	}
	Find(p);Find(x/p);
} 
int N,k;
vector<int>ans;
map<int,vector<int> >Map;
map<int,bool>used,vis;
map<int,int>now;
int a[1010];
signed main(){
	N=read(),k=read();
	if(k==1){
		printf("0\n");return 0;
	}
	srand(time(NULL));
	for(int i=1;i<=N;++i){
//		ans=0;
		a[i]=n=read();
		if(n<=2){
			Map[n].pb(n);
			pm[i].insert(n);
//			printf("Prime\n");
		}
		else if(Miller_Rabin(n)){
			Map[n].pb(n);
			pm[i].insert(n);
//			printf("Prime\n");
		}
		else{
			st.clear();
			Find(n);
			if(st.size()==1){
				Map[*st.begin()].pb(n);
			}
			pm[i]=std::move(st);
		}
	}
	int sum=0;
	int b3=0;
	for(auto i:Map){
		if(i.se.size()>1){
			used[i.fi]=1;
			if(i.se.size()>=3) b3=i.fi;
			sum+=i.se.size();
		}
	}
//	printf("%d %d\n",sum,b3);
	if(sum>=k){
		if(b3){
			int cnt=k;
			vector<int>ans;
			if(k&1){
				for(auto i:Map){
					if(i.fi==b3){
						ans.pb(i.se[0]);
						ans.pb(i.se[1]);
						ans.pb(i.se[2]);
						k-=3;
						now[i.fi]=3;break ;
					}
				}
			}
			if(k%2==0){
				for(auto i:Map){
					if(i.se.size()>1){
						if(k>=2&&!now[i.fi]){
							k-=2;now[i.fi]=2;ans.pb(i.se[0]);ans.pb(i.se[1]);
						}
					}
				}
				for(auto i:Map){
					if(i.se.size()>1){
						while(now[i.fi]<i.se.size()&&k){
							--k;ans.pb(i.se[now[i.fi]]);++now[i.fi];
						}
					}
				}
			}
			for(int i:ans) printf("%lld ",i);
			return 0;
		}
		else{
			if(k%2==0){
				int cnt=0;
				for(auto i:Map){
					if(i.se.size()>1){
						++cnt;
						printf("%lld %lld ",i.se[0],i.se[1]);
						if(cnt*2==k){
							return 0;
						}
					}
				}
			}
			else{
				int mxn=k>>1,cnt=0;
				for(int i=1;i<=N;++i){
					if(pm[i].size()>1&&pm[i].size()<=mxn){
						bool f=1;
						for(int p:pm[i]){
							if(!used.count(p)){
								f=0;
								break ;
							}
						}
						if(!f) continue ;
						printf("%lld ",a[i]);
						for(int p:pm[i]){
							++cnt;used[p]=0;
							printf("%lld %lld ",Map[p][0],Map[p][1]);
						}
						break ;
					}
				}
				if(!cnt){
					printf("0\n");return 0;
				}
				if(cnt==mxn) return 0;
				for(auto i:Map){
					if(used[i.fi]){
						++cnt;
						printf("%lld %lld ",i.se[0],i.se[1]);
						if(cnt==mxn) return 0;
					}
				}
			}
		}
	}
	else{
		for(auto i:Map){
			if(i.se.size()>1){
				used[i.fi]=1;
				for(int j:i.se){
					vis[j]=1;ans.pb(j);
				}
			}
		}
		for(int i=1;i<=N;++i){
			if(!vis.count(a[i])){
				bool f=0;
				for(auto j:pm[i]){
					if(!used[j]){
						f=1;break ;
					}
				}
				if(!f){
					ans.pb(a[i]);
				}
			}
		}
		if(ans.size()>=k){
			for(int i=0;i<k;++i) printf("%lld ",ans[i]);
			return 0;
		}
	}
	printf("0\n");
}