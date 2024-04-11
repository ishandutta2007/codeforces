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
using namespace __gnu_pbds;
using namespace std;
const int mod = 0;
const int maxn = 100100;
inline void flush(){cout.flush(),fflush(stdout);}
typedef unsigned long long u64;
typedef unsigned u32;
typedef long long ll;
template<typename T>using heap=__gnu_pbds::priority_queue<T>;
template<typename T>using rbt=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>inline istream&operator,(istream&cin,T&x){return cin>>x;}
template<typename T>inline ostream&operator,(ostream&cout,const T&x){return cout<<x;}
template<typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template<typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
istream&in=cin;ostream&out=cout;
inline int pow(int a,int b,int ans=1){
	for(;b;b>>=1,a=ll(a)*a%mod)
		if(b&1)ans=ll(ans)*a%mod;
	return ans;
}
inline int inv(int a){return pow(a,mod-2);}
int n,k,A,B;
int a[maxn];
int L[maxn*40],R[maxn*40],sz[maxn*40],tot;
inline void add(int&rt,int pos,ll l,ll r){
	if(!rt)rt=++tot;
	++sz[rt];
	if(l==r)return;
	ll mid=l+r>>1;
	if(pos<=mid)add(L[rt],pos,l,mid);
	else add(R[rt],pos,mid+1,r);
}
inline ll solve(int&rt,ll l,ll r){
	if(!rt)return A;
	if(l==r)return B*sz[rt];
	ll mid=l+r>>1;
	ll ans=solve(L[rt],l,mid)+solve(R[rt],mid+1,r);
	return std::min(ans,B*(r-l+1)*sz[rt]);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	in,n,k,A,B;
	int rt=0;
	for(int i=1;i<=k;++i)in,a[i],add(rt,a[i],1,(1ll<<n));
	std::cout << solve(rt,1,(1ll)<<n) << '\n';
}