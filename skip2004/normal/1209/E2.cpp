#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace __gnu_pbds;
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2001000;
inline void flush(){cout.flush(),fflush(stdout);}
typedef unsigned long long u64;
typedef unsigned u32;
typedef long long ll;
typedef long double ld;
template<typename t>using heap=__gnu_pbds::priority_queue<t>;
template<typename t>using rbt=tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename t>inline istream&operator,(istream&cin,t&x){return cin>>x;}
template<typename t>inline ostream&operator,(ostream&cout,const t&x){return cout<<x;}
template<typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template<typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
istream&in=cin;ostream&out=cout;
inline int pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=ll(a)*a%mod)
        if(b&1)ans=ll(ans)*a%mod;
    return ans;
}
inline int inv(int a){return pow(a,mod-2);}
int f[1 << 12],g[1 << 12],h[1 << 12];
int a[100][5000];
int mx[5000];
int rk[5000];
int n,m;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int t;
	in,t;
	while(t--){
		in,n,m;
		rep(i,1,m) mx[i] = 0;
		rep(i,0,n-1) rep(j,1,m){
			in,a[i][j]; up(mx[j],a[i][j]);
		}
		rep(j,1,m) rk[j] = j;
		std::sort(rk + 1,rk + m + 1,[](int x,int y){ return mx[x] > mx[y]; });
		rep(i,0,(1<<n)-1) f[i] = g[i] = h[i] = 0;
		rep(i,1,std::min(n,m)){
			int j = rk[i];
			rep(ii,0,n-1){
				rep(i,0,(1<<n)-1) f[i] = g[i];
				rep(l,0,n-1){
					const int pos = (l + ii) % n;
					rep(k,0,(1<<n)-1){
						if(k >> l & 1) continue;
						up(f[k | 1 << l],f[k] + a[pos][j]);
					}
				}
				rep(i,0,(1<<n)-1) up(h[i],f[i]);
			}
			rep(i,0,(1<<n)-1) g[i] = h[i];
		}
		out,g[(1 << n)-1],'\n';
	}
}