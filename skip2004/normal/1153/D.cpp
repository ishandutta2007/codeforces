#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace __gnu_pbds;
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1001000;
inline void flush(){cout.flush(),fflush(stdout);}
typedef unsigned long long u64;
typedef unsigned u32;
typedef long long ll;
typedef long double ld;
template<typename T>using heap=__gnu_pbds::priority_queue<T>;
template<typename T>using rbt=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>inline istream&operator,(istream&cin,T&x){return cin>>x;}
template<typename T>inline ostream&operator,(ostream&cout,const T&x){return cout<<x;}
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
int n;
int tp[maxn];
int fa[maxn];
vector<int> to[maxn];
int size[maxn];
int dp[maxn];
inline void dfs(int x){
	size[x]=to[x].empty();
	for(int i:to[x]){
		dfs(i);
		size[x]+=size[i];
	}
	dp[x]=1;
	if(tp[x]==1)
		for(int i:to[x])
			up(dp[x],size[x]-size[i]+dp[i]);
	else {
		for(int i:to[x])
			dp[x]+=dp[i]-1;
	}
}
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	in,n;
	for(int i=1;i<=n;++i)std::cin >> tp[i];
	for(int i=2,x;i<=n;++i)
		std::cin >> x,to[x].push_back(i);
	dfs(1);
	std::cout << dp[1] << '\n';
}